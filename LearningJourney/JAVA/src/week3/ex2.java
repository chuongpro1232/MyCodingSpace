package week3;

public class ex2 {
    public static void main(String args[]) {
        java.util.Random r = new java.util.Random();
        int[] numbers = new int[100000];
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = r.nextInt(10000);
        }
        StopWatch stopWatch = new StopWatch();
        stopWatch.selectionSort(numbers);
        stopWatch.stop();
        System.out.println("Sorting 100000 numbers took " +
                stopWatch.getElapsedTime() + " milliseconds");
    }
}

class StopWatch {
    private long startTime;
    private long endTime = startTime;

    public StopWatch() {
        this.startTime = System.currentTimeMillis();
    }

    public long getStartTime() {
        return startTime;
    }

    public long getEndTime() {
        return endTime;
    }

    public void start() {
        this.startTime = System.currentTimeMillis();
    }

    public void stop() {
        this.endTime = System.currentTimeMillis();
    }

    public long getElapsedTime() {
        return this.endTime - this.startTime;
    }

    public static void selectionSort(int[] list) {
        for (int i = 0; i < list.length; i++) {
            int currentMin = list[i];
            int currentMinIndex = i;
            for (int j = i + 1; j < list.length; j++) {
                if (currentMin > list[j]) {
                    currentMin = list[j];
                    currentMinIndex = j;
                }
            }
            if (currentMinIndex != i) {
                list[currentMinIndex] = list[i];
                list[i] = currentMin;
            }
        }
    }
}