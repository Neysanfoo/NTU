import java.util.Arrays;

public class QuickSort {
  public static void main(String[] args) {
    int[] a = {2, 8, 1, 3, 6, 7, 5, 4};
    System.out.println(Arrays.toString(a));
    sort(a);
    System.out.println(Arrays.toString(a));
  }

  public static void sort(int[] a) {
    shuffle(a);
    sort(a, 0, a.length - 1);
  }

  public static void sort(int[] a, int lo, int hi) {
    if (hi <= lo) return;
    int j = partition(a, lo, hi);
    sort(a, lo, j - 1);
    sort(a, j + 1, hi);
  }

  public static int partition(int[] a, int lo, int hi) {
    int i = lo, j = hi + 1;
    int v = a[lo];
    while (true) {
      while (a[++i] < v) {
        if (i == hi) break;
      }
      while (v < a[--j]) {
        if (j == lo) break;
      }
      if (i >= j) break;
      swap(a, i, j);
    }
    swap(a, lo, j);
    return j;
  }

  public static void shuffle(int[] a) {
    int N = a.length;
    for (int i = 0; i < N; i++) {
      int r = (int) (Math.random() * (i + 1)); // random int between 0 and i
      swap(a, i, r);
    }
  }

  public static void swap(int[] a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }
}
