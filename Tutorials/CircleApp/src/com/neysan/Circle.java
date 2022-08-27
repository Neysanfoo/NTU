package com.neysan;

public class Circle {
  private double radius; // radius of circle
  private static final double PI = 3.14159;
  // constructor
  public Circle(double rad) {
    this.radius = rad;
  }
  // mutator method - set radius
  public void setRadius(double rad) {
    this.radius = rad;
  } // accessor method - get radius

  public double getRadius() {
    return radius;
  }

  // calculate area
  public double area() {
    return this.radius * this.radius * PI;
  }
  // calculate circumference
  public double circumference() {
    return this.radius * 2 * PI;
  }
  // print area
  public void printArea() {
    System.out.println(area());
  }
  // print circumference
  public void printCircumference() {
    System.out.println(circumference());
  }
}
