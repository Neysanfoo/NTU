import java.util.Arrays;

public class InsertionSort {
  public static void main(String[] args) {
    int[] a = {2, 8, 1, 3, 6, 7, 5, 4};
    System.out.println(Arrays.toString(a));
    sort(a);
    System.out.println(Arrays.toString(a));
  }

  public static void sort(int[] a) {
    int N = a.length;
    for (int i = 1; i < N; i++) {
      for (int j = i; j > 0; j--) {
        if (a[j] < a[j-1])
          swap(a, j, j-1);
        else break;
      }
    }
  }

  public static void swap(int[] a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }
}
