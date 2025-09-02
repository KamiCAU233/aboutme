import java.util.*;

public class TodayIsTuesday {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int today = 2;
        for (int i = 0; i < 100; i++) {
            today = today % 7 + 1;
        }
        System.out.println(today);
    }
}
