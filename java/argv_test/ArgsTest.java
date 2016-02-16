import java.util.ArrayList;

public class ArgsTest {
    public static void main(String[] args) {
        int args_state = 0;
        ArrayList<String> input_files = new ArrayList<String>();

        for (String arg: args) {
            /* arg changes the state (-X) */
            if (arg.charAt(0) == '-') {
                args_state = 0;
            }
            if (arg.equals("-i")) {
                /* input file name */ 
                args_state = 1;
                continue;
            }

            /* in each state (elements after -X) */
            if (args_state == 1){
                input_files.add(arg);
            }
        }

        ArrayList<String> input_txt_files = new ArrayList<String>();
        for (String input_file: input_files) {
            // filter non-txt files
            if (input_file.endsWith(".txt")) {
                input_txt_files.add(input_file);
            }
        }

        for (String input_file: input_txt_files) {
            System.out.println(input_file);
        }
    }
}
