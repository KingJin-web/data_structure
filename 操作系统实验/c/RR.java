


import java.text.DecimalFormat;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/**
 * 轮转调度算法
 *
 * @ClassName: RouletteSchedule
 */
public class RR {
    private static int finishTime = 0;

    public static void main(String[] args) {

//        @SuppressWarnings("resource")
//        Scanner s = new Scanner(System.in);
        int q = 2; // 时间片段RR

        Process A = new Process(0,4);
        Process B = new Process(1,3);
        Process C = new Process(2,4);
        Process D = new Process(3,2);
        Process E = new Process(4,4);

        //传到真正的服务时间
        A.setRealServerTime(A.getServerTime());
        B.setRealServerTime(B.getServerTime());
        C.setRealServerTime(C.getServerTime());
        D.setRealServerTime(D.getServerTime());
        E.setRealServerTime(E.getServerTime());

        LinkedList<Process> list = new LinkedList<Process>();
        list.add(A);
        list.add(B);
        list.add(C);
        list.add(D);
        list.add(E);


        //获取并移除队列的头
        Process p;
        while((p = list.poll()) !=null ) {
            //进程服务的时间 小于等于 时间片段p
            if(p.getServerTime() <= q) {
                p.setFinishTime(finishTime + p.getServerTime());
                finishTime += p.getServerTime();
                p.setTurnoverTime(p.getFinishTime() - p.getArriveTime());
                p.setQuanTurnoverTime((double) p.getTurnoverTime() / (double)p.getRealServerTime());
            }else if(p.getServerTime() > q){ //大于
                p.setFinishTime(finishTime + q);
                finishTime += q;
                p.setServerTime(p.getServerTime() - q);
                list.add(p);//将进程移植队尾
            }
        }

        print(A);
        print(B);
        print(C);
        print(D);
        print(E);

        //打印平均周转时间
        avgTurnoverTime(A,B,C,D,E);
        //打印带权周转时间
        avgQuanTurnoverTime(A,B,C,D,E);
    }

    /**
     * 打印输出结果
     * @Title: print
     * @return void
     */

    //格式化小数，保留两位小数
    static DecimalFormat df = new DecimalFormat("0.00");

    private static int i = 1;
    public static void print(Process p) {
        System.out.println("第"+(i++)+"个进程     完成时间: "+p.getFinishTime()+"\t周转时间: "+
                p.getTurnoverTime()+"\t带权周转时间："+df.format(p.getQuanTurnoverTime()));
    }

    /**
     * 平均周转时间
     */
    public static void avgTurnoverTime(Process...process) {
        int i = 0;
        double sum = 0;
        for (Process p : process) {
            sum += p.getTurnoverTime();
            i++;
        }
        System.out.println("平均周转时间为："+sum/i);
    }

    /**
     * 平均带权周转时间
     */
    public static void avgQuanTurnoverTime(Process...process) {
        int i = 0;
        double sum = 0;
        for (Process p : process) {
            sum += p.getQuanTurnoverTime();
            i++;
        }
        System.out.println("平均带权周转时间为："+df.format(sum/i));
    }

}

