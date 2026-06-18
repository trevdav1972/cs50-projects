import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd
from datetime import datetime

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    if request.method == "POST":
        return apology("TODO")
    else:
        user_id = session["user_id"]
        purchases = db.execute("SELECT * FROM purchases WHERE user_id = ?", user_id)
        cash = db.execute("SELECT cash FROM users WHERE id = :user_id", user_id=user_id)
        available_cash = cash[0]['cash']
        return render_template("index.html", purchases=purchases, cash=available_cash)
@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "GET":
        return render_template("buy.html")
    else:
        symbol = request.form.get("symbol")
        result = lookup(symbol)

        if result is None:
            return apology("Invalid symbol")
        share = request.form.get("shares")
        if not share.isdigit():
            return apology("shares has to be a digit")
        if share.isdigit():
            share = int(share)
            if share == 0:
                return apology("shares can't be less than 0")

        price = result["price"]
        user_id=session["user_id"]
        name = result["name"]
        cash = db.execute("SELECT cash FROM users WHERE id = :user_id", user_id=user_id)
        available_cash = cash[0]['cash']
        cost = price * share
        new_available_cash = available_cash - cost
        if cost >= available_cash:
            return apology("not enough cash")
        else:
            db.execute("INSERT INTO purchases (user_id, symbol, shares, price, total, name) VALUES (?, ?, ?, ?, ?, ?);", user_id, symbol, share, price, cost, name)
            db.execute("UPDATE users SET cash = ? WHERE id = ?", new_available_cash, user_id)
            return redirect("/")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    if request.method == "GET":
        return render_template("history.html")

    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "GET":
        return render_template("quote.html")
    else:
        symbol = request.form.get("symbol")
        result = lookup(symbol)
        if result is None:
            return apology("Invalid symbol")
        else:
            return render_template("quoted.html", result=result, )

@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "GET":
        return render_template("register.html")
    else:

        username = request.form.get("username")
        username1 = db.execute("SELECT username FROM users WHERE username = ? ", username)
        password = request.form.get("password")
        hash = generate_password_hash(password)
        password1 = request.form.get("confirmation")
        password2 = db.execute("SELECT hash FROM users WHERE username = ?", username)

        # Ensure username was submitted
        if not username:
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not password:
            return apology("must provide password", 400)

        # Ensure password was submitted
        elif not password1:
            return apology("must confirm password", 400)

        # Ensure password equals confirmation
        elif  password != password1:
            return apology("password doesn't match", 400)

        # this gets the username that they inputted.
        else:
            print("Username: ", username)
            print("Hash: ", hash)
            print("Password", password)
            print("Password1", password1)
            if password2:
                print("Password2", password2[0]['hash'])
            else:
                print("nothing")
            if username1:
                print("username1", username1[0]['username'])
            else:
                print('nothing1')

            if username1 and 'username' in username1[0]:
                return apology("username already exists", 400)
            else:
                result = db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)
                print("Result: ", result)
                id = db.execute("SELECT id FROM users WHERE username = ?", username)
                session["user_id"] = id[0]["id"]
                return redirect ("/")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "GET":
        user_id = session["user_id"]
        purchases = db.execute("SELECT * FROM purchases WHERE user_id = ?", user_id)
        return render_template("sell.html", purchases = purchases)
    else:
        user_id = session["user_id"]
        shares = request.form.get("shares")
        if not shares.isdigit():
            return apology("shares needs to be a digit")
        shares = int(shares)
        symbol = request.form.get("symbol")
        result = lookup(symbol)
        price = result["price"]
        name = result["name"]
        if symbol is None:
            return apology("Missing Symbol")
        if shares < 0:
            return apology("Missing Shares")
        total_shares = db.execute("SELECT SUM(shares) FROM purchases WHERE user_id = ? AND symbol = ?", user_id, symbol)
        total_shares = total_shares[0]['SUM(shares)']
        if shares > total_shares:
            return apology("Not enough Shares")

        cost = shares * price
        cash = db.execute("SELECT cash FROM users WHERE id = :user_id", user_id=user_id)
        cash = cash[0]['cash']
        new_cash = cash + cost
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, user_id)

        total_shares -= shares
        print("total_shares: ", total_shares)
        db.execute("INSERT INTO purchases (user_id, symbol, shares, price, total, name, transaction_time) VALUES (?, ?, -?, ?, ?, ?, datetime('now'));", user_id, symbol, shares, price, cost, name)
        return redirect("/")
