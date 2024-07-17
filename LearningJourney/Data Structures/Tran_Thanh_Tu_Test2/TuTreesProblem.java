package Tran_Thanh_Tu_Test2;

public class TuTreesProblem {
    private final int[] X;
    private final int[] P;
    private final int M;
    private final int L;

    public TuTreesProblem(int[] X, int[] P, int M, int L) {
        this.X = X;
        this.P = P;
        this.M = M;
        this.L = L;
    }

    // maxProfit complexity = O(N)
    public int maxProfit() {
        int maxProfit = 0;
        for (int profit : P) {
            maxProfit += profit;
        }
        return maxProfit;
    }

    // firstThree complexity = O(N * logN)
    public int[] firstThree() {
        int[] tempX = sortP();
        int[] firstThree = new int[tempX.length >= 3 ? 3 : tempX.length];
        for (int i = 0; i < firstThree.length; i++) {
            firstThree[i] = tempX[tempX.length - 1 - i];
        }
        return firstThree;
    }

    // maxProfitDP time complexity = O(n)
    public int maxProfitDP() {
        int[] mp = new int[P.length];
        for (int i = 0; i < mp.length; i++) {
            if (i > 0) {
                if (X[i] - X[i - 1] >= L) {
                    mp[i] = mp[i - 1] + P[i];
                    System.out.print(i + " ");
                } else {
                    if (P[i] > mp[i - 1]) {
                        System.out.print(i + " ");
                        mp[i] = P[i];
                    } else {
                        mp[i] = mp[i - 1];
                    }
                }
            } else {
                System.out.print(i + " ");
                mp[i] = P[i];
            }
        }
        return mp[mp.length - 1];
    }

    private int[] sortP() {
        int[] tempX = new int[X.length];
        int[] tempP = new int[P.length];
        copyArray(X, tempX);
        copyArray(P, tempP);
        quickSort(new int[][] { tempX, tempP }, 0, tempX.length - 1);
        return tempX;
    }

    private void copyArray(int[] orig, int[] target) {
        for (int i = 0; i < target.length; i++) {
            target[i] = orig[i];
        }
    }

    private void quickSort(int[][] a, int left, int right) {
        if (left < right) {
            int j = left - 1;
            for (int i = left; i < right; i++) {
                if (a[1][i] < a[1][right]) {
                    j++;
                    swap(a[0], i, j);
                    swap(a[1], i, j);
                }
            }
            j++;
            swap(a[0], right, j);
            swap(a[1], right, j);
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
        int[] X = { 1, 4, 5, 7, 8, 10 };
        int[] P = { 4, 5, 3, 2, 6, 1 };
        int M = 10;
        int L = 2;
        TuTreesProblem treesProblem = new TuTreesProblem(X, P, M, L);
        System.out.println(treesProblem.maxProfit());
        System.out.println(Arrays.toString(treesProblem.firstThree()));
        System.out.println(treesProblem.maxProfitDP());
    }
}
