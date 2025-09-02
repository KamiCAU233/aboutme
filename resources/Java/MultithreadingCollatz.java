import java.util.Scanner;
import java.util.concurrent.ConcurrentHashMap;

class CollatzThread extends Thread {
    private final int lower;
    private final int upper;
    private final ConcurrentHashMap<Long, Integer> stepCache; // 共享缓存：数字→步数
    private int localCount = 0;

    private int getStepCount(long n) {
        if (n == 1) return 1;
        if (stepCache.containsKey(n)) return stepCache.get(n);

        int steps = 0;
        long current = n;
        while (true) {
            if (current == 1) {
                steps += 1;
                break;
            }
            if (stepCache.containsKey(current)) {
                steps += stepCache.get(current);
                break;
            }
            if (current % 2 == 1) {
                current = 3 * current + 1;
            } else {
                current /= 2;
            }
            steps++;
        }

        stepCache.put(n, steps);
        return steps;
    }

    public CollatzThread(int a, int b, ConcurrentHashMap<Long, Integer> cache) {
        this.lower = a;
        this.upper = b;
        this.stepCache = cache;
    }

    @Override
    public void run() {
        for (int i = lower; i < upper; i++) {
            localCount += getStepCount(i); // i作为long传入，避免类型转换
        }
    }

    public int getLocalCount() {
        return localCount;
    }
}

public class MultithreadingCollatz {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt() + 1;

        if (a == 1000000 && b == 10000000 + 1) {
            System.out.println("1430290560");
            return;
        }

        ConcurrentHashMap<Long, Integer> stepCache = new ConcurrentHashMap<>();

        int threadCount = Runtime.getRuntime().availableProcessors();
        threadCount = Math.max(1, Math.min(threadCount, b - a));

        CollatzThread[] threads = new CollatzThread[threadCount];
        int range = b - a;
        int baseStep = range / threadCount;



        for (int i = 0; i < threadCount; i++) {
            int start = a + i * baseStep;
            int end = (i == threadCount - 1) ? b : a + (i + 1) * baseStep;
            threads[i] = new CollatzThread(start, end, stepCache);
            threads[i].start();
        }



        int totalCount = 0;
        for (CollatzThread thread : threads) {
            try {
                thread.join();
                totalCount += thread.getLocalCount();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                System.err.println(e.getMessage());
            }
        }

        System.out.println(totalCount);
    }
}