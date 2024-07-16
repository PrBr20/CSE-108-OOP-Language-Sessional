public class Club {
    private int id;
    private String name;
    private int point;


    public Club(){}
    public void setId(int x) {id = x;}
    public void setName(String x) {name = x;}


    public int getId() {return id;}
    public String getName() {return  name;}
    public void addPoint(int x) { point += x;}
    public int getPoint() {return point;}

}