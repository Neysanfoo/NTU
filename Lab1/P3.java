import java.util.Scanner;

public class P3 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println("Starting: ");
    int starting = scanner.nextInt();
    System.out.println("Ending: ");
    int ending = scanner.nextInt();
    System.out.println("Increment: ");
    int increment = scanner.nextInt();
    if (starting > ending) {
      System.out.println("Error: Ending value must be greater than or equal to starting value.");
      return;
    }
    System.out.println("US$         S$");
    System.out.println("--------------");
    for (int i = starting; i <= ending; i += increment) {
      System.out.println(i + "         " + i * 1.82); 
    }
  }
}
