import java.util.Scanner;

public class P1 {
  private static final Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int choice;
    int m,n;

    do {
      System.out.println("Perform the following methods:");
      System.out.println("1: multiplication test");
      System.out.println("2: quotient using division by subtraction");
      System.out.println("3: remainder using division by subtraction");
      System.out.println("4: count the number of digits");
      System.out.println("5: position of a digit");
      System.out.println("6: extract all odd digits");
      System.out.println("7: quit");
      choice = sc.nextInt();
      switch (choice) {
        case 1: /* add mulTest() call */
          mulTest();
          break;
        case 2: /* add divide() call */
          System.out.println("Enter m:");
          m = sc.nextInt();
          System.out.println("Enter n:");
          n = sc.nextInt();
          System.out.println(divide(m,n)); 
          break;
        case 3: /* add modulus() call */
          System.out.println("Enter m:");
          m = sc.nextInt();
          System.out.println("Enter n:");
          n = sc.nextInt();
          System.out.println(modulus(m, n));
          break;
        case 4: /* add countDigits() call */
          System.out.println("Enter a number: ");
          m = sc.nextInt();
          System.out.println(countDigits(m));
          break;
        case 5: /* add position() call */
          System.out.println("Enter a number:");
          m = sc.nextInt();
          System.out.println("Enter a digit: ");
          n = sc.nextInt();
          System.out.println(position(m, n));
          break;
        case 6: /* add extractOddDigits() call */
          System.out.println("Enter a number:");
          m = sc.nextInt();
          System.out.println(extractOddDigits(m));
          break;
        case 7:
          System.out.println("Program terminating ...");
      }
    } while (choice < 7);
  }
  /* add method code here */
  public static void mulTest() {
    int rand1, rand2, ans, sol;
    int correctCount = 0;
    for (int i = 0; i < 5; i++) {
      rand1 = (int) (Math.random() * 10);
      rand2 = (int) (Math.random() * 10);
      System.out.print("How much is " + rand1 + " times " + rand2 + "? ");
      ans = sc.nextInt();
      sol = rand1 * rand2;
      if (ans == sol) {
        correctCount++;
      }
    }
    System.out.println(correctCount + " answers out of 5 are correct.");
    System.out.println("---------------------------------------------");
  }

  public static int divide(int m, int n) {
    int minusCount = 0;
    while (m > 0) {
      m -= n;
      if (m >= 0) minusCount++;
    }
    return minusCount;
  }

  public static int modulus(int m, int n) {
    while (m >= 0) {
      m -= n;
    }
    return m + n;
  }

  public static int countDigits(int n) {
    if (n < 0) {
      System.out.println("Input cannot be less than 0");
      return -1;
    }
    int count = 0;
    while (n > 0) {
      n /= 10;
      count++;
    }
    return count;
  }

  public static int position(int n, int digit) {
    int index = 1;
    int lastDigit;
    while (n > 0) {
      lastDigit = n % 10;
      if (lastDigit == digit) return index;
      index++;
      n /= 10;
    }
    return -1;
  }
  
  public static long extractOddDigits(long n) {
    if (n < 0) {
      System.out.println("Input cannot be less than 0.");
      return -1;
    }
    long oddDigits = 0;
    long lastDigit;
    int k = 0;
    while (n > 0) {
      lastDigit = n % 10;
      if (lastDigit % 2 != 0) {
        oddDigits += lastDigit * (Math.pow(10, k));
        k++;
      }
      n /= 10;
    }
    if (oddDigits == 0) return -1;
    return oddDigits;
  }
}
