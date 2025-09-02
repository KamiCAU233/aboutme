import java.util.Scanner;

public class Renminbi {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double amount = sc.nextDouble();
        amount *= 100;
        int num = (int)Math.round(amount);
        int yuan100 = num / 10000;
        num = num - 10000 * yuan100;
        int yuan50 = num / 5000;
        num = num - 5000 * yuan50;
        int yuan20 = num / 2000;
        num = num - 2000 * yuan20;
        int yuan10 = num / 1000;
        num = num - 1000 * yuan10;
        int yuan5 = num / 500;
        num = num - 500 * yuan5;
        int yuan1 = num / 100;
        num = num - 100 * yuan1;
        int jiao5 = num / 50;
        num = num - 50 * jiao5;
        int jiao1 = num / 10;
        num = num - 10 * jiao1;
        int fen5 = num / 5;
        num = num - 5 * fen5;
        int fen1 = num;
        System.out.println(yuan100 + " " + yuan50 + " " + yuan20 + " " + yuan10 + " " + yuan5 + " " + yuan1
                           + " " + jiao5 + " " + jiao1 + " " + fen5 + " " + fen1 + " ");
    }
}
