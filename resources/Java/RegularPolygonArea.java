import java.util.Scanner;

public class RegularPolygonArea {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int s = sc.nextInt();
        int n = sc.nextInt();
        double area = n * s * s / (4 * Math.tan(Math.PI / n));
        System.out.printf("%.3f", area);
    }
}
