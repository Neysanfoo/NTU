// Implementation of Quicksort using the NTU algorithm

import java.util.Arrays;

public class QuickSortNTU {
  public static void main(String[] args) {
    int[] a = {2, 8, 1, 3, 6, 7, 5, 4};
    System.out.println(Arrays.toString(a));
    sort(a);
    System.out.println(Arrays.toString(a));
  }

  public static void sort(int a[]) {
    sort(a, 0, a.length - 1);
  }

  public static void sort(int[] a, int lo, int hi) {
    if (hi <= lo) return;
    int pivot_pos = partition(a, lo, hi);
    sort(a, lo, pivot_pos - 1);
    sort(a, pivot_pos + 1, hi);
  }

  public static int partition(int[] a, int lo, int hi) {
    int i, last_small, pivot;
    int mid = (lo + hi) / 2;
    swap(a, lo, mid);
    pivot = a[lo];
    last_small = lo;
    for (i = lo + 1; i <= hi; i++) {
      if (a[i] < pivot) {
        swap(a, ++last_small, i);
      }
    }
    swap(a, lo, last_small);
    return last_small;
  }

  public static void swap(int[] a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }
}
