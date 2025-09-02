import java.lang.reflect.Array;
import java.util.*;

public class MarketBasketAnalysis {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Map<Set<Integer>, Integer> edgesCount = new HashMap<>();
        String invoice = "";

        while (true) {
            invoice = sc.nextLine();
            if (invoice.equals("00000")) {
                break;
            }
            Set<Integer> invoices = new HashSet<>();
            for (String str : invoice.split(" ")) {
                invoices.add(Integer.parseInt(str));
            }
            List<Integer> list = new ArrayList<>(invoices);
            for (int i = 0; i < list.size(); i++) {
                for (int j = i + 1; j < list.size(); j++) {
                    Set<Integer> pair = new TreeSet<>();
                    pair.add(list.get(i));
                    pair.add(list.get(j));
                    // The merge method is a invalid in Xueba
                    // edgesCount.merge(pair, 1, Integer::sum);
                    if (edgesCount.get(pair) == null) {
                        edgesCount.put(pair, 1);
                    } else {
                        edgesCount.put(pair, edgesCount.get(pair) + 1);
                    }
                }
            }
        }
        // Find the greatest value in edgesCount
        int maxCount = Collections.max(edgesCount.values());
        for (Set<Integer> s : edgesCount.keySet()) {
            if (edgesCount.get(s) == maxCount) {
                for (Integer i : s) {
                    System.out.print(i + " ");
                }
                System.out.print("\n");
            }
        }
    }
}
