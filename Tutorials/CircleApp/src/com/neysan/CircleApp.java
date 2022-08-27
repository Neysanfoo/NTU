package com.neysan;

import java.util.Scanner;

public class CircleApp {
  public static void main(String[] args) {
    printMenu();
  }

  public static void printMenu() {
    Scanner scanner = new Scanner(System.in);
    Circle circle = new Circle(0);
    while (true) {
      System.out.println(
          "==== Circle Computation =====\n"
              + "|1. Create a new circle     |\n"
              + "|2. Print Area              |\n"
              + "|3. Print circumference     |\n"
              + "|4. Quit                    |\n"
              + "=============================\n"
              + "Choose option (1-3):");
      int choice = scanner.nextInt();
      switch (choice) {
        case 1:
          System.out.println("Enter the radius to compute the area and circumference");
          double radius = scanner.nextDouble();
          circle.setRadius(radius);
          break;
        case 2:
          circle.printArea();
          break;
        case 3:
          circle.printCircumference();
          break;
        default:
          scanner.close();
          return;
      }
    }
  }
}
