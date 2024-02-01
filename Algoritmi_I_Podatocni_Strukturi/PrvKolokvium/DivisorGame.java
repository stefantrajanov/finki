public class DivisorGame {
    public boolean divisorGame(int n) {
        if (n % 2 == 0){
            return true;
        }

        for (int i = 0; true; i++) {
            boolean flag = true;
            for (int j = n - 1; j > 0; j--) {
                if (n % j == 0){
                    n -= j;
                    flag = false;
                    break;
                }
            }

            if (i % 2 == 0){
                if (n % 2 == 0){
                    return false;
                }
                if (flag){
                    return false;
                }
            }else{
                if (flag){
                    return true;
                }
            }
        }
    }

    public static void main(String[] args) {

    }
}
