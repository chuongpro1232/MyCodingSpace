package Tran_Thanh_Tu_Test2.Test;

public class TuFireProblem {
    private final int[] kids;
    private final int limit;

    public TuFireProblem(int[] kids, int limit) {
        this.kids = kids;
        this.limit = limit;
    }

    // minLimit complexity = O(N^2)
    public int posCombination() {
        int count = 0;
        for (int i = 0; i < kids.length - 1; i++) {
            for (int j = i + 1; j < kids.length; j++) {
                if (kids[i] + kids[j] <= limit) {
                    count++;
                }
            }
        }
        return count;
    }

    // minLimit complexity = O(N)
    public int minLimit() {
        int minKid = Integer.MIN_VALUE;
        int maxKid = Integer.MAX_VALUE;
        for (int kid : kids) {
            minKid = minKid < kid ? kid : minKid;
            maxKid = maxKid > kid ? kid : maxKid;
        }
        return minKid + maxKid;
    }

    // maxRescue complexity = O(N * logN)
    public int maxRescue() {
        int[] sortedKids = sortKids();
        int left = 0;
        int right = sortedKids.length - 1;
        int maxRescue = 0;
        while (left <= right) {
            if (sortedKids[left] + sortedKids[right] > limit) {
                right--;
            } else {
                left++;
                right--;
            }
            maxRescue++;
        }
        return maxRescue;
    }

    private int[] sortKids() {
        int[] sortedKids = new int[kids.length];
        for (int i = 0; i < sortedKids.length; i++) {
            sortedKids[i] = kids[i];
        }
        quickSort(sortedKids, 0, sortedKids.length - 1);
        return sortedKids;
    }

    // quickSort complexity = O(N * log N)
    private void quickSort(int[] a, int left, int right) {
        if (left < right) {
            int j = left - 1;
            for (int i = left; i < right; i++) {
                if (a[i] < a[right]) {
                    swap(a, i, ++j);
                }
            }
            swap(a, right, ++j);
            quickSort(a, left, j - 1);
            quickSort(a, j + 1, right);
        }
    }

    private void swap(int[] a, int i, int j) {
        int temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }

    public static void main(String[] args) {
        int[] kids = { 10, 15, 12, 14, 25, 28, 16, 13 };
        int limit = 30;
        TuFireProblem fireProblem = new TuFireProblem(kids, limit);
        System.out.println(fireProblem.posCombination());
        System.out.println(fireProblem.minLimit());
        System.out.println(fireProblem.maxRescue());
    }
}
