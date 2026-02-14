class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
         if(!poured)
         return 0;

         vector<double> excess;
         excess.push_back(poured);

         int i = 0;

         while(i < query_row)
         {
             bool notAllZero = 0; 
             vector<double> newRow;

             for(int idx = 0; idx <= i; idx++)
             {
                double idxGlassShare = 0.0;

                if(idx)  // left upper not for first glass
                idxGlassShare += (excess[idx-1] - 1.0)/2.0;

                if(idxGlassShare < 0)
                idxGlassShare = 0;

                double tmp = (excess[idx] - 1.0)/2.0;  // just upper share

                if(tmp < 0)
                tmp = 0;

                idxGlassShare += tmp;

                newRow.push_back(idxGlassShare);
                if(idxGlassShare)
                notAllZero = 1;
             }

             // for last Glass
             double lastGlassShare = (excess[i] - 1.0)/2.0;
             if(lastGlassShare < 0)
              lastGlassShare = 0;

             if(lastGlassShare)
              notAllZero = 1;

             newRow.push_back(lastGlassShare);

             if(!notAllZero)
             return 0.0;

             excess = newRow;

             i++;
         }


         return excess[query_glass] > 1 ? 1 : excess[query_glass];
    }
};