
import java.io.*;
import java.nio.charset.StandardCharsets;

public class rBat {
    public void setbat() {
        String cmd = "@echo off\r\n" + "ipconfig/all\r\n" + "pause";
        String url = ".\\查看ip.bat";
        FileWriter fw = null;
        try {
            // 生成bat文件
            fw = new FileWriter(url);
            fw.write(cmd);
            fw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            // 运行bat文件
            Process process = Runtime.getRuntime().exec(url);
            InputStream in = process.getInputStream();
            String line;
            BufferedReader br = new BufferedReader(new InputStreamReader(in, StandardCharsets.UTF_8));
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
            in.close();
            process.waitFor();
            System.out.println("执行成功");
        } catch (Exception e) {
            System.out.println("执行失败");
        }
    }

    public static void main(String[] args) {
        rBat bat = new rBat();
        bat.setbat();
    }

}
