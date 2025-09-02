import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.util.Scanner;

public class PiCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        N--;
        BigInteger s = getBigInteger(N);
        BigInteger pi = s.multiply(BigInteger.valueOf(4));
        System.out.println(pi.toString().substring(0, N + 1));
    }

    private static BigInteger getBigInteger(int N) {
        BigInteger base = BigInteger.TEN.pow(N + 10);
        BigInteger x1 = base.multiply(BigInteger.valueOf(4)).divide(BigInteger.valueOf(5));
        BigInteger x2 = base.negate().divide(BigInteger.valueOf(239));
        BigInteger s = x1.add(x2);

        for (int i = 3; i <= N * 2; i += 2) {
            x1 = x1.divide(BigInteger.valueOf(-25));
            x2 = x2.divide(BigInteger.valueOf(-57121));
            BigInteger t = x1.add(x2).divide(BigInteger.valueOf(i));
            s = s.add(t);
        }
        return s;
    }
}