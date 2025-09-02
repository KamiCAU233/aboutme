import java.util.Scanner;

class PrimeCounterThread extends Thread {
    private final int lowerBound;
    private final int upperBound;
    private int localCount = 0;

    public PrimeCounterThread(int lowerBound, int upperBound) {
        this.lowerBound = lowerBound;
        this.upperBound = upperBound;
    }

    @Override
    public void run() {
        for (int i = lowerBound; i <= upperBound; i++) {
            if (i < 2) continue; // 跳过小于2的数
            if (isPrime(i)) {
                localCount++;
                // System.out.println(i + " is prime.");
            }
        }
    }

    public int getLocalCount() {
        return localCount;
    }

    public static boolean isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        int sqrt = (int) Math.sqrt(n);
        for (int i = 5; i <= sqrt; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}

public class MultithreadingFindPrime {
    public static void main(String[] args) {
        // 读取输入
        Scanner scanner = new Scanner(System.in);
        int lower, upper;
        lower = scanner.nextInt();
        upper = scanner.nextInt();

        int range = upper - lower + 1;
        int threadCount = Math.min(
                Runtime.getRuntime().availableProcessors(), Math.max(1, range / 100)
        );
        threadCount = Math.min(4, threadCount); // 最大4个线程
        PrimeCounterThread[] threads = new PrimeCounterThread[threadCount];

        for (int i = 0; i < threadCount; i++) {
            int start = lower + (i * range) / threadCount;
            int end = lower + ((i + 1) * range) / threadCount - 1;

            if (i == threadCount - 1) {
                end = upper;
            }

            threads[i] = new PrimeCounterThread(start, end);
            threads[i].start();
        }

        int total = 0;
        for (Thread thread : threads) {
            try {
                thread.join();
                total += ((PrimeCounterThread) thread).getLocalCount();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return;
            }
        }

        System.out.println(total);
    }
}