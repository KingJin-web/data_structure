/**
 * 进程类Process
 * 
 * @ClassName: Process
 */
public class Process {
    private int arriveTime;// 到达时间
    private int serverTime;// 服务时间，可以修改
    private int finishTime;// 完成时间
    private int turnoverTime;// 周转时间
    private double quanTurnoverTime;// 带权周转时间

    public int getRealServerTime() {
        return realServerTime;
    }

    public void setRealServerTime(int realServerTime) {
        this.realServerTime = realServerTime;
    }

    private int realServerTime; // 真正的服务时间，不能修改

    public Process() {
    }

    public Process(int arriveTime, int serverTime) {
        super();
        this.arriveTime = arriveTime;
        this.serverTime = serverTime;
    }

    public int getArriveTime() {
        return arriveTime;
    }

    public void setArriveTime(int arriveTime) {
        this.arriveTime = arriveTime;
    }

    public int getServerTime() {
        return serverTime;
    }

    public void setServerTime(int serverTime) {
        this.serverTime = serverTime;
    }

    public int getFinishTime() {
        return finishTime;
    }

    public void setFinishTime(int finishTime) {
        this.finishTime = finishTime;
    }

    public int getTurnoverTime() {
        return turnoverTime;
    }

    public void setTurnoverTime(int turnoverTime) {
        this.turnoverTime = turnoverTime;
    }

    public double getQuanTurnoverTime() {
        return quanTurnoverTime;
    }

    public void setQuanTurnoverTime(double quanTurnoverTime) {
        this.quanTurnoverTime = quanTurnoverTime;
    }

}
