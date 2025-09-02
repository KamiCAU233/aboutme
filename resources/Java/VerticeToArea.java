import java.util.Scanner;

public class VerticeToArea {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x1 = sc.nextInt();
        int y1 = sc.nextInt();
        int x2 = sc.nextInt();
        int y2 = sc.nextInt();
        int x3 = sc.nextInt();
        int y3 = sc.nextInt();
        newPoint p1 = new newPoint(x1, y1);
        newPoint p2 = new newPoint(x2, y2);
        newPoint p3 = new newPoint(x3, y3);
        double a = newPoint.getDistance(p1, p2);
        double b = newPoint.getDistance(p2, p3);
        double c = newPoint.getDistance(p1, p3);
        double p = (a + b + c) / 2;
        double area = Math.sqrt(p * (p - a) * (p - b) * (p - c));
        System.out.printf("%.3f %.3f %.3f %.3f", c, b, a, area);
    }
}

class newPoint {
    public int x;
    public int y;
    public newPoint(int x, int y) {
        this.x = x;
        this.y = y;
    }
    public static double getDistance(newPoint p1, newPoint p2) {
        return Math.sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }
}

