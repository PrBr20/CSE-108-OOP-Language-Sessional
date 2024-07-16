public class League {
    private Match[] matches;
    private int matchCount;
    private int clubCount;
    private Club[] clubs;
    private Club[] clubStandings;
    private String name;
    // add your variables here, if required

    public League() {
        // assume a league can have at most 5 clubs, add code for initialization accordingly
        clubCount = 0;
        matchCount = 0;

        clubs = new Club[5];
        clubStandings = new Club[5];
    }

    public void printLeagueInfo(){
        System.out.println("League : " + name);
        printClubs();
    }

    public void printClubs(){
        System.out.println("Clubs:");
        // print the name of the clubs of this league, each one on a line

        for(int i=0; i<clubCount; i++){
            System.out.println(clubs[i].getName());
        }
    }

    public void scheduleMatches(){
        matchCount = (clubCount*(clubCount-1));
        matches = new Match[matchCount];
        int matchNo = 0;
        for (int i=0; i<clubCount; i++){
            for (int j=0; j<clubCount; j++){
                // check the constructor of the Match class and add your code here
                // note that there will be two matches between club A and club B
                // in the first match, club A will play as the home team and in the second match, as the away team
                if(i == j) continue;

                Match temp = new Match(matchNo, clubs[i], clubs[j]);
                matches[matchNo] =  temp;
                matchNo++;
            }
        }
    }

    public void simulateMatches(){
        for (int i=0; i<matchCount; i++){
            matches[i].play();
        }
    }

    public void showStandings(){
        // sort the clubs in descending order of points
        // note that, the sequence in which clubs were added to the league, should be unchanged
        // check the given sample output for clarification
        // (carefully observe the output of showStandings() followed by printLeagueInfo() method calls
        // you can use additional arrays if needed


        for(int i=0; i<clubCount; i++){
            clubStandings[i] = clubs[i];
        }

        for(int i=0; i<clubCount; i++){
            int mx = clubStandings[i].getPoint(), ind = i;

            for(int j = i+1; j<clubCount; j++){
                if(clubStandings[j].getPoint() > mx) {
                    mx = clubStandings[j].getPoint();
                    ind = j;
                }
            }

            Club temp = new Club();
            temp = clubStandings[i];
            clubStandings[i] = clubStandings[ind];
            clubStandings[ind] = temp;
        }


        System.out.println("Sl. - Club - Points");

        // print the clubsStandings in descending order of points

        for(int i=0; i<clubCount; i++){
            System.out.println(i+1 + ". " + clubStandings[i].getName() + " " + clubStandings[i].getPoint());
        }
        
    }

    // add your methods here, if required

    public void setName(String x){ name = x; }

    public void addClub(Club x){
        clubs[clubCount] = x;
        clubCount++;
    }

    public void printMatches(){
        for(int i=0; i<matchCount; i++){
            matches[i].showResult();
        }
    }

    public void removeClub(Club c){
        for(int i = 0; i < clubCount; i++){
            boolean fou = false;
            if(clubs[i].getId() == c.getId()){
                fou = true;
                for(int j = i+1; j < clubCount; j++){
                    clubs[j - 1] = clubs[j];
                }
            }
            if(fou) break;
        }
        clubCount--;
    }

}

