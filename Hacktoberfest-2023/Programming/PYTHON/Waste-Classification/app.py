from flask import Flask, render_template, request, jsonify
import requests
import tensorflow as tf
import numpy as np
import json
import os

app = Flask(__name__)

UPLOADS = './static/uploads/'

def pre_process(img):
    img = tf.keras.preprocessing.image.load_img(img, target_size=(96, 96))
    img = tf.keras.preprocessing.image.img_to_array(img)
    img = np.expand_dims(img, axis=0)
    return img


@app.route('/',methods=['GET','POST'])
def home():
    return render_template("home.html")


@app.route("/resultpage", methods=["POST", "GET"])
def result():
    if(request.method=="POST"):
        img = request.files['filename']
        img.save(UPLOADS+'test.jpg')
        img = pre_process(UPLOADS+'test.jpg')

        model = tf.keras.models.load_model("D:\Anki\Python Projects\Workspace\MyHacktoberfest2023\Hacktoberfest2023\projects\Waste-Classification\mobilenet_finetune.h5")
        result = model.predict(img)

        pred = result[0][0]
        if pred<0:
            txt ="Your Waste is Bio-Degradable!"
        else:
            txt ="Your Waste is Non-Biodegradable"

        os.remove(UPLOADS+'test.jpg')
        return jsonify({"pred":str(pred),"text":txt})


@app.route('/info')
def info():
    return render_template("info.html")


if __name__ == "__main__":
	app.run(debug=True,host="0.0.0.0",port="8080")