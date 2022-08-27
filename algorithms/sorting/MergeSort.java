import java.util.Arrays;

public class MergeSort {
  public static void main(String[] args) {
    int[] a = {2, 8, 1, 3, 6, 7, 5, 4};
    System.out.println(Arrays.toString(a));
    sort(a);
    System.out.println(Arrays.toString(a));
  }

  public static void merge(int[] a, int[] aux, int lo, int mid, int hi) {
    assert isSorted(a, lo, mid);
    assert isSorted(a, mid + 1, hi);

    for (int k = lo; k <= hi; k++) {
      aux[k] = a[k];
    }

    int i = lo, j = mid + 1;

    for (int k = lo; k <= hi; k++) {
      if (i > mid) a[k] = aux[j++];
      else if (j > hi) a[k] = aux[i++];
      else if (aux[j] < aux[i]) a[k] = aux[j++];
      else a[k] = aux[i++];
    }
    assert isSorted(a, lo, hi);
  }

  private static void sort(int[] a, int[] aux, int lo, int hi) {
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    sort(a, aux, lo, mid);
    sort(a, aux, mid + 1, hi);
    merge(a, aux, lo, mid, hi);
  }

  public static boolean isSorted(int[] array, int lo, int hi) {
    for (int i = lo; i < hi; ++i) {
      if (array[i] > (array[i + 1])) return false;
    }
    return true;
  }

  public static void sort(int[] a) {
    int[] aux = new int[a.length];
    sort(a, aux, 0, a.length - 1);
  }
}
