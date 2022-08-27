public class Dice {
  private int valueOfDice;

  public Dice(int valueOfDice) {
    this.valueOfDice = valueOfDice;
  }

  public void setValueOfDice(int valueOfDice) {
    this.valueOfDice = valueOfDice;
  }

  public int getValueOfDice() {
    return valueOfDice;
  }

  public void printDiceValue() {
    System.out.println(this.valueOfDice);
  }
}
