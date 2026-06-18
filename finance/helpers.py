import csv
import datetime
import pytz
import requests
import subprocess
import urllib
import uuid

from flask import redirect, render_template, session
from functools import wraps


def apology(message, code=400):
    """Render message as an apology to user."""
    def escape(s):
        """
        Escape special characters.

        https://github.com/jacebrowning/memegen#special-characters
        """
        for old, new in [("-", "--"), (" ", "-"), ("_", "__"), ("?", "~q"),
                         ("%", "~p"), ("#", "~h"), ("/", "~s"), ("\"", "''")]:
            s = s.replace(old, new)
        return s
    return render_template("apology.html", top=code, bottom=escape(message)), code


def login_required(f):
    """
    Decorate routes to require login.

    http://flask.pocoo.org/docs/0.12/patterns/viewdecorators/
    """
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)
    return decorated_function


import yfinance as yf

def lookup(symbol):
    """Look up quote for symbol using yfinance."""
    try:
        # Use yfinance to fetch the stock object
        stock = yf.Ticker(symbol)
        
        # Get the latest market price
        # 'fast_info' is a fast, lightweight way to get the current price
        price = stock.fast_info['last_price']
        
        return {
            "name": symbol.upper(),
            "price": round(float(price), 2),
            "symbol": symbol.upper()
        }
    except Exception as e:
        print(f"DEBUG: yfinance error: {e}")
        return None


def usd(value):
    """Format value as USD."""
    return f"${value:,.2f}"
