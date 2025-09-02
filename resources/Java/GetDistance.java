import java.util.Scanner;
import java.lang.Math;
public class GetDistance {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x1 = sc.nextInt();
        int y1 = sc.nextInt();
        int x2 = sc.nextInt();
        int y2 = sc.nextInt();
        newPoint p1 = new newPoint(x1, y1);
        newPoint p2 = new newPoint(x2, y2);
        double distance = newPoint.getDistance(p1, p2);
        System.out.printf("%.3f\n", distance);
    }
}

class Point {
    public int x;
    public int y;
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
    public static double getDistance(newPoint p1, newPoint p2) {
        return Math.sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }
}


