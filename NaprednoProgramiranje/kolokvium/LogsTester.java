import java.sql.Timestamp;
import java.util.*;


class Log {
    public String serviceName;
    public String microServiceName;
    public String type;
    public String message;
    public String timestamp;

    public Log(String serviceName, String microServiceName, String type, String message, String timestamp) {
        this.serviceName = serviceName;
        this.microServiceName = microServiceName;
        this.type = type;
        this.message = message;
        this.timestamp = timestamp;
    }

    public double getSeverityValue() {
        switch (this.type) {
            case "WARN": {
                if (this.message.contains("might cause error")) {
                    return 2;
                }
                return 1;
            }
            case "ERROR": {
                double value = 3;
                if (this.message.contains("fatal")) {
                    value += 2;
                }
                if (this.message.contains("exception")) {
                    value += 3;
                }

                return value;
            }
            default:
                return 0;
        }
    }

    public int getTimestamp() {
        return Integer.parseInt(timestamp);
    }

    @Override
    public String toString() {
        return String.format("%s|%s [%s] %s%s T:%s",
                this.serviceName, this.microServiceName, this.type, this.message, this.timestamp, this.timestamp
                );
    }
}

class Service {
    public String name;
    public Set<String> microServices;
    public List<Log> logs;

    public Service(String name) {
        this.name = name;
        this.logs = new ArrayList<>();
        this.microServices = new HashSet<>();
    }

    public void addNewLog(Log log) {
        this.microServices.add(log.microServiceName);
        this.logs.add(log);
    }

    public double getAverageSeverity() {
        double average = 0;
        for (Log log : logs) {
            average += log.getSeverityValue();
        }

        return average / this.logs.size();
    }

    public List<Integer> severityLevels(String microservice) {
        List<Integer> result = new ArrayList<>();

        for (Log log : logs) {
            if (microservice != null) {
                if (log.microServiceName.contentEquals(microservice)) {
                    result.add((int) log.getSeverityValue());
                }
            } else {
                result.add((int) log.getSeverityValue());
            }
        }

        return result;
    }

    public List<Log> getMicroserviceLogs(String microservice) {
        List<Log> result = new ArrayList<>();

        for (Log log : logs) {
            if (microservice != null) {
                if (log.microServiceName.contentEquals(microservice)) {
                    result.add(log);
                }
            }
            else{
                result.add(log);
            }
        }

        return result;
    }

    public double getAverageNumberOfLogsPerMicroservice() {
        if (this.microServices.size() == 0) {
            return 0;
        }

        return (double) this.logs.size() / (double) this.microServices.size();
    }

    @Override
    public String toString() {
        return String.format(
                "Service name: %s Count of microservices: %d Total logs in service: %d Average severity for all logs: %.2f Average number of logs per microservice: %.2f"
                , this.name, this.microServices.size(), this.logs.size(), this.getAverageSeverity(), this.getAverageNumberOfLogsPerMicroservice()
        );
    }
}

//service_name microservice_name type message timestamp, каде што type може да биде INFO, WARN и ERROR.
class LogCollector {
    public Map<String, Service> services;

    public LogCollector() {
        this.services = new HashMap<>();
    }

    public void addLog(String log) {
        String[] split = log.split(" ");

        String serviceName = split[0];
        String microServiceName = split[1];
        String type = split[2];
        StringBuilder builder = new StringBuilder();
        for (int i = 3; i < split.length - 1; i++) {
            builder.append(split[i]).append(" ");
        }
        String message = builder.toString();
        String timestamp = split[split.length - 1];

        if (!this.services.containsKey(serviceName)) {
            this.services.putIfAbsent(serviceName, new Service(serviceName));
            this.services.get(serviceName).addNewLog(new Log(serviceName, microServiceName, type, message, timestamp));
        } else {
            this.services.get(serviceName).addNewLog(new Log(serviceName, microServiceName, type, message, timestamp));
        }
    }

    public void printServicesBySeverity() {
        List<Service> temp = new ArrayList<>(this.services.values());
        temp.sort(Comparator.comparing(Service::getAverageSeverity).reversed());
        temp.forEach(System.out::println);
    }

    public Map<Integer, Integer> getSeverityDistribution(String serviceName, String microservice) {
        Map<Integer, Integer> map = new TreeMap<>();
        Service service = this.services.get(serviceName);
        List<Integer> temp = service.severityLevels(microservice);

        for (int value : temp) {
            if (!map.containsKey(value)) {
                map.putIfAbsent(value, 1);
            } else {
                map.put(value, map.get(value) + 1);
            }
        }

        return map;
    }

    public void displayLogs(String service, String microservice, String order) {
        List<Log> logs = this.services.get(service).getMicroserviceLogs(microservice);
        if (order.contentEquals("NEWEST_FIRST")){
            logs.sort(Comparator.comparing(Log::getTimestamp).reversed());

        }else if (order.contentEquals("OLDEST_FIRST")){
            logs.sort(Comparator.comparing(Log::getTimestamp));

        }else if (order.contentEquals("MOST_SEVERE_FIRST")){
            logs.sort(Comparator.comparing(Log::getSeverityValue).thenComparing(Log::getTimestamp).reversed());

        }else if (order.contentEquals("LEAST_SEVERE_FIRST")){
            logs.sort(Comparator.comparing(Log::getSeverityValue));
        }

        logs.forEach(System.out::println);
    }
}

public class LogsTester {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LogCollector collector = new LogCollector();
        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            if (line.startsWith("addLog")) {
                collector.addLog(line.replace("addLog ", ""));
            } else if (line.startsWith("printServicesBySeverity")) {
                collector.printServicesBySeverity();
            } else if (line.startsWith("getSeverityDistribution")) {
                String[] parts = line.split("\\s+");
                String service = parts[1];
                String microservice = null;
                if (parts.length == 3) {
                    microservice = parts[2];
                }
                collector.getSeverityDistribution(service, microservice).forEach((k, v) -> System.out.printf("%d -> %d%n", k, v));
            } else if (line.startsWith("displayLogs")) {
                String[] parts = line.split("\\s+");
                String service = parts[1];
                String microservice = null;
                String order = null;
                if (parts.length == 4) {
                    microservice = parts[2];
                    order = parts[3];
                } else {
                    order = parts[2];
                }
                System.out.println(line);

                collector.displayLogs(service, microservice, order);
            }
        }
    }
}