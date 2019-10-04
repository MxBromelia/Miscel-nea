s(Count) --> s_a(Count), s_b(Count), s_c(Count).

s_a(0) --> [].
s_a(seq(Count)) --> [a], s_a(Count).

s_b(0) --> [].
s_b(seq(Count)) --> [b], s_b(Count).

s_c(0) --> [].
s_c(seq(Count)) --> [c], s_c(Count).

s_ct(Count) --> s_ct_a(Count), s_ct_b(Count), s_ct_c(Count).

s_ct_a(0) --> [].
s_ct_a(Count) --> [a], s_ct_a(NewCount), {Count is NewCount+1}.

s_ct_b(0) --> [].
s_ct_b(Count) --> [b], s_ct_b(NewCount), {Count is NewCount+1}.

s_ct_c(0) --> [].
s_ct_c(Count) --> [c], s_ct_c(NewCount), {Count is NewCount+1}.

s_2  -->  ablock(Count),bblock(Count),cblock(Count). 
    
   ablock(0)  -->  []. 
   ablock(NewCount)  -->  [a],ablock(Count), 
                                             {NewCount  is  Count  +  1}. 
    
   bblock(0)  -->  []. 
   bblock(NewCount)  -->  [b],bblock(Count), 
                                             {NewCount  is  Count  +  1}. 
    
   cblock(0)  -->  []. 
   cblock(NewCount)  -->  [c],cblock(Count), 
                                             {NewCount  is  Count  +  1}.