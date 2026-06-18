from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/")
def index():
    # if "name" in request.args:
    #     name = request.args["name"]
    # else:
    #     name = "world"
    # return render_template("index.html", name=name)

    return render_template("index.html")

@app.route("/greet", methods=["POST"])
def greet():
    return render_template("greet.html", name=request.args.get("name", "world"))