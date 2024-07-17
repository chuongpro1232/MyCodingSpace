package Tran_Thanh_Tu_Test2;

public class TuHolidayProblem {
    private final int[][] distances;
    private final int N;

    public TuHolidayProblem(int[][] distances) {
        this.distances = distances;
        N = distances.length;
    }

    // nearestCity timeComplexity = O(N)
    public int nearestCity() {
        int nearestCity = 1;
        for (int i = 1; i < N; i++) {
            if (distances[0][i] > 0) {
                nearestCity = distances[0][nearestCity] < distances[0][i] ? nearestCity : i;
            }
        }
        return nearestCity;
    }

    public int shortestPath() {

        return 0;
    }

    public int maxVisited() {
        return 0;
    }

    public static void main(String[] args) {
        int[][] distances = {
                { 0, 30, 10, 0 },
                { 30, 0, 10, 40 },
                { 10, 10, 0, 80 },
                { 0, 40, 80, 0 }
        };
        TuHolidayProblem holidayProblem = new TuHolidayProblem(distances);
        System.out.println(holidayProblem.nearestCity());
        System.out.println(holidayProblem.shortestPath());
        System.out.println(holidayProblem.maxVisited());

    }

    public class IntQueue {
        private int size;
        private int front, rear;

        private static int MAX_SIZE = 1000;
        private Integer[] items;

        public IntQueue() {
            size = 0;
            front = rear = 0;
            items = new Integer[MAX_SIZE];
        }

        public int size() {
            return size;
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public boolean enQueue(int item) {
            if (size < MAX_SIZE) {
                items[rear] = item;
                rear = (rear + 1) % MAX_SIZE;
                size++;
                return true;
            }
            return false;
        }

        public boolean deQueue() {
            if (isEmpty()) {
                return false;
            }
            front = (front + 1) % MAX_SIZE;
            size--;
            return true;
        }

        public Integer peekFront() {
            if (isEmpty()) {
                return null;
            }
            return items[front];
        }
    }
}
