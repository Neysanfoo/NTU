package com.neysan;

import java.util.Scanner;

/** VendingMachine */
public class VendingMachine {
  public VendingMachine() {}

  public double selectDrink() {
    Scanner sc = new Scanner(System.in);
    String msg =
        "====== Vending Machine ======\n"
            + "|1. Buy Beer ($3.00)        |\n"
            + "|2. Buy Coke ($1.00)        |\n"
            + "|3. Buy Green Tea ($5.00)   |\n"
            + "|===========================|\n"
            + "Please enter selection:";
    System.out.println(msg);
    int choice = sc.nextInt();
    sc.close();
    switch (choice) {
      case 1:
        return 3;
      case 2:
        return 1;
      case 3:
        return 5;
      default:
        return -1;
    }
  }

  public double insertCoins(double drinkCost) {
    double coinsInserted = 0;
    Scanner sc = new Scanner(System.in);
    String msg =
        " Please insert coins:"
            + "========== Coins Input ===========\n"
            + "|Enter 'Q' for ten cents input   |\n"
            + "|Enter 'T' for twenty cents input|\n"
            + "|Enter 'F' for fifty cents input |\n"
            + "|Enter 'N' for a dollar input    |\n"
            + "==================================";
    System.out.println(msg);
    while (coinsInserted < drinkCost) {
      int choice = sc.nextInt();
      switch (choice) {
        case 'Q':
          coinsInserted += 0.1;
          break;
        case 'T':
          coinsInserted += 0.2;
          break;
        case 'F':
          coinsInserted += 0.5;
          break;
        case 'N':
          coinsInserted += 1;
          break;
        default:
          sc.close();
          return -1;
      }
      System.out.println("Coins inserted: " + coinsInserted);
    }
    sc.close();
    return coinsInserted - drinkCost;
  }

  public void checkChange(double amount, double drinkCost) {}

  public void printReceipt() {}
}
