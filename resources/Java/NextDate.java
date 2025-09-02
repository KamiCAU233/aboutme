import java.util.Scanner;

public class NextDate {
    public static boolean isLeap(int y) {
        if (y % 4 == 0 && y % 100 != 0) {
            return true;
        } else if (y % 400 == 0) {
            return true;
        } else {
            return false;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int year = sc.nextInt();
        int month = sc.nextInt();
        int day = sc.nextInt();
        int[] days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeap(year)) days_in_month[1] = 29;
        if (day != days_in_month[month - 1]) {
            day++;
        } else if (month != 12) {
            day = 1;
            month++;
        } else {
            year++;
            month = 1;
            day = 1;
        }
        System.out.printf("%d %d %d \n", year, month, day);
    }
}
