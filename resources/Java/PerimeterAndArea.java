import java.util.Scanner;

public class PerimeterAndArea {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double radius = sc.nextDouble();
        double area = 3.14 * radius * radius;
        double perimeter = 2 * 3.14 * radius;
        System.out.printf("%.2f\n", area);
        System.out.printf("%.2f", perimeter);
    }
}
