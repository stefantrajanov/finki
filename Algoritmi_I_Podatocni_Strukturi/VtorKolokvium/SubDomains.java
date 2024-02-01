import java.util.*;

public class SubDomains {
    public static void main(String[] args) {
        String[] cpdomains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org", "10 pero.co"};

        HashMap<String, Integer> map = new HashMap<>();

        for (int i = 0; i < cpdomains.length; i++) {
            String[] split = cpdomains[i].split(" ");
            String current = split[1];

            String[] currentSplit = current.split("\\.");

            for (int j = 0; j < currentSplit.length; j++) {
                StringBuilder builder = new StringBuilder();
                for (int k = j; k < currentSplit.length; k++) {
                    builder.append(currentSplit[k]).append(".");
                }
                builder.deleteCharAt(builder.length() - 1);

                map.put(builder.toString(), 0);
                builder = new StringBuilder();
            }
        }

        for (int i = 0; i < cpdomains.length; i++) {
            String[] split = cpdomains[i].split(" ");
            String current = split[1];
            map.put(current, Integer.parseInt(split[0]));
        }

        List<String> main = new ArrayList<>();
        for (String key : map.keySet()) {
            int sum = 0;
            for (String compareKey : map.keySet()) {
                if (!key.contains(".")){
                    String[] split = compareKey.split("\\.");

                    for (String value : split) {
                        if (key.compareTo(value) == 0){
                            sum += map.get(compareKey);
                        }
                    }

                }else {
                    if (compareKey.contains(key)) {
                        sum += map.get(compareKey);
                    }
                }
            }

            map.replace(key, sum);
            main.add(map.get(key) + " " + key);
        }


        System.out.println(main);

        System.out.println(map);
    }
}

class SolutionSubDomains {
//    public List<String> subdomainVisits(String[] cpdomains) {
//        HashMap<String, Integer> map = new HashMap<>();
//
//        for (int i = 0; i < cpdomains.length; i++) {
//            String[] split = cpdomains[i].split(" ");
//            String current = split[1];
//
//            String[] currentSplit = current.split("\\.");
//
//            for (int j = 0; j < currentSplit.length; j++) {
//                StringBuilder builder = new StringBuilder();
//                for (int k = j; k < currentSplit.length; k++) {
//                    builder.append(currentSplit[k]).append(".");
//                }
//                builder.deleteCharAt(builder.length() - 1);
//
//                map.put(builder.toString(), 0);
//                builder = new StringBuilder();
//            }
//        }
//
//        for (int i = 0; i < cpdomains.length; i++) {
//            String[] split = cpdomains[i].split(" ");
//            String current = split[1];
//            map.put(current, Integer.parseInt(split[0]));
//        }
//
//        List<String> main = new ArrayList<>();
//        for (String key : map.keySet()) {
//            int sum = 0;
//            for (String compareKey : map.keySet()) {
//                if (!key.contains(".")){
//                    String[] split = compareKey.split("\\.");
//
//                    for (String value : split) {
//                        if (key.compareTo(value) == 0){
//                            sum += map.get(compareKey);
//                        }
//                    }
//
//                }else {
//                    if (compareKey.contains(key)) {
//                        sum += map.get(compareKey);
//                    }
//                }
//            }
//
//            map.replace(key, sum);
//            main.add(map.get(key) + " " + key);
//        }
//
//        return main;
//    }
public static List<String> subdomainVisits(String[] cpdomains) {
    Map<String, Integer> domainCount = new HashMap<>();

    for (String cpdomain : cpdomains) {
        String[] parts = cpdomain.split(" ");
        int count = Integer.parseInt(parts[0]);
        String domain = parts[1];

        updateDomainCount(domainCount, domain, count);

        while (domain.contains(".")) {
            int dotIndex = domain.indexOf(".");
            domain = domain.substring(dotIndex + 1);
            updateDomainCount(domainCount, domain, count);
        }
    }

    List<String> result = new ArrayList<>();
    for (Map.Entry<String, Integer> entry : domainCount.entrySet()) {
        result.add(entry.getValue() + " " + entry.getKey());
    }

    return result;
}

    private static void updateDomainCount(Map<String, Integer> domainCount, String domain, int count) {
        domainCount.put(domain, domainCount.getOrDefault(domain, 0) + count);
    }
}

//811. Subdomain Visit Count