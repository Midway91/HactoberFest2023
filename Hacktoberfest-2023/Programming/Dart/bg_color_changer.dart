//  Random BackgroundColor Changer
//  Run this project by visiting the following link

//  https://dartpad.dev/?id=03a45a66e3895bdcc3d68f7613ef0adb


import 'package:flutter/material.dart';
import 'dart:math';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: "minimize time",
      theme: ThemeData.dark(),
      home: Practice(),
    );
  }
}

class Practice extends StatefulWidget {
  @override
  PracticeState createState() => PracticeState();
}

class PracticeState extends State<Practice> {
  //declarations
  String currentColorName = "colors";
  var currentBgColor = Colors.black;
  var nextBgColors = [
    Colors.amber,
    Colors.grey,
    Colors.yellow,
    Colors.green,
    Colors.indigo,
    Colors.lime,
    Colors.orange,
    Colors.pink,
    Colors.purple,
    Colors.blue,
    Colors.red
  ];
  //display
  void display() {
    setState(() {
      var rand = Random().nextInt(nextBgColors.length);
      currentBgColor = nextBgColors[rand];

      switch (rand) {
        case 0:
          currentColorName = "amber";
          break;
        case 1:
          currentColorName = "grey";
          break;
        case 2:
          currentColorName = "yellow";
          break;
        case 3:
          currentColorName = "green";
          break;
        case 4:
          currentColorName = "indigo";
          break;
        case 5:
          currentColorName = "lime";
          break;
        case 6:
          currentColorName = "orange";
          break;
        case 7:
          currentColorName = "pink";
          break;
        case 8:
          currentColorName = "purple";
          break;
        case 9:
          currentColorName = "blue";
          break;
        case 10:
          currentColorName = "red";
          break;
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Container(
        color: currentBgColor,
        child: Center(
          child: Text(
            currentColorName,
            style: const TextStyle(
              fontSize: 100,
              fontWeight: FontWeight.bold,
            ),
          ),
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: display,
        backgroundColor: currentBgColor,
        child: const Icon(
          Icons.refresh,
          color: Colors.white,
          size: 40,
        ),
      ),
      floatingActionButtonLocation: FloatingActionButtonLocation.centerFloat,
    );
  }
}
