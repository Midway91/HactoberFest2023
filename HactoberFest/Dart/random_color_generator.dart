import 'dart:math';

void main() {
  Random random = new Random();

  print(
      'rgb(${random.nextInt(256)},${random.nextInt(256)},${random.nextInt(256)})');
}
