import java.util.Arrays;

public class SelectionSort {
  public static void main(String[] args) {
    int[] a = {2, 8, 1, 3, 6, 7, 5, 4};
    System.out.println(Arrays.toString(a));
    sort(a);
    System.out.println(Arrays.toString(a));
  }

  public static void sort(int[] a) {
    int min, temp;
    int N = a.length;
    for (int i = 0; i < N - 1; i++) {
      min = i;
      for (int j = i + 1; j < N; j++) {
        if (a[j] < a[min]) min = j;
      }
      // Swap a[min] and a[i]
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
    }
  }
}
