import java.util.Scanner;

public class DiceApp {
  public static void main(String[] args) {
    int totalValue = 0;
    Scanner sc = new Scanner(System.in);

    System.out.println("Press 1 to roll the first dice");
    if (sc.nextInt() != 1) {
      System.out.println("Wrong key");
      sc.close();
      return;
    }
    int firstRoll = (int) (1 + Math.random() * 6);
    Dice firstDice = new Dice(firstRoll);
    totalValue += firstRoll;
    System.out.println("Current value is " + firstDice.getValueOfDice());
    

    System.out.println("Press 2 to roll the second dice");
    if (sc.nextInt() != 2) {
      System.out.println("Wrong key");
      sc.close();
      return;
    }
    int secondRoll = (int) (1 + Math.random() * 6);
    Dice secondDice = new Dice(secondRoll);
    totalValue += secondRoll;
    System.out.println("Current value is " + secondDice.getValueOfDice());

    System.out.println("Your total number is: " + totalValue);
    sc.close();
  }
}
