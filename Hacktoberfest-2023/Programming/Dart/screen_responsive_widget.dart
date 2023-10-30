import 'package:flutter/material.dart';

typedef ResponsiveBuilder = Widget Function(bool isWide, double width);

class ResponsiveWidget extends StatelessWidget {
  final ResponsiveBuilder builder;

  const ResponsiveWidget({Key? key, required this.builder}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return LayoutBuilder(
      builder: (_, box) => OrientationBuilder(
          builder: (_, orientation) =>
              builder(orientation == Orientation.landscape, box.maxWidth)),
    );
  }
}
