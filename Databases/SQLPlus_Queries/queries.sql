rem CS 340 Programming Assignment 1
rem Zuhaib Asad
rem 19100201

Prompt 1
Select P.Pat_id
From Patent P, Categories C
Where P.cat = C.cat AND P.subcat = C.subcat AND (C.catnamelong = 'Chemical' OR C.catnamelong = 'Drugs AND Medical');

Prompt 2
Select I.firstname, I.lastname, I.country, I.postate
From (Inventor I INNER JOIN Patent P ON I.patentnum = P.Pat_id) , Categories C
Where P.cat = C.cat AND P.subcat = C.subcat AND (C.catnamelong = 'Chemical' OR C.catnamelong = 'Drugs AND Medical');

Prompt 3
Select I1.firstname, I1.lastname, I1.country, I1.postate
From (Inventor I1 INNER JOIN Patent P1 ON I1.patentnum = P1.Pat_id) , Categories C1
Where P1.cat = C1.cat AND P1.subcat = C1.subcat AND C1.catnamelong = 'Chemical' AND (C1.cat, C1.subcat) NOT IN
(Select C.cat, C.subcat
From (Inventor I INNER JOIN Patent P ON I.patentnum = P.Pat_id) , Categories C
Where P.cat = C.cat AND P.subcat = C.subcat AND C.catnamelong != 'Chemical');

Prompt 4
Select I.patentnum
From Inventor I
Where I.postate = 'CA' OR I.postate = 'NJ';

Prompt 5
Select I.patentnum
From Inventor I
Where  (I.invseq = 1 AND (I.postate = 'CA' OR I.postate = 'NJ')) AND EXISTS
(Select I1.lastname , I1.firstname , I1.patentnum, I1.invseq, I1.postate
 From Inventor I1
 Where I.patentnum = I1.patentnum AND (I1.invseq = 2 AND (I1.postate = 'CA' OR I1.postate = 'NJ')) );

Prompt 6
Select T.CN
From ( Select C.compname AS CN, Count(P.pat_id) AS CNT
	   FROM Company C INNER JOIN Patent P ON P.assignee = C.assignee		
	   Group By C.compname) T
Where T.CNT IN ( Select Max(Count(P1.pat_id))
	   			 FROM Company C1 INNER JOIN Patent P1 ON P1.assignee = C1.assignee		
	   			 Group By C1.compname ) ;

Prompt 7
Select T.CN
From ( Select C.compname AS CN, Count(P.pat_id) AS CNT
	   FROM (Company C INNER JOIN Patent P ON P.assignee = C.assignee), Categories CT
	   Where P.cat = CT.cat AND P.subcat = CT.subcat AND CT.catnamelong = 'Chemical'
	   Group By C.compname) T
Where T.CNT IN (
				Select Max(Count(P1.pat_id))
				FROM (Company C1 INNER JOIN Patent P1 ON P1.assignee = C1.assignee), Categories CT1		
				Where P1.cat = CT1.cat AND P1.subcat = CT1.subcat AND CT1.catnamelong = 'Chemical'
				Group By C1.compname
				);

Prompt 8
Select C.compname
FROM (Company C INNER JOIN Patent P ON P.assignee = C.assignee), Categories CT		
Where P.cat = CT.cat AND P.subcat = CT.subcat AND CT.catnamelong = 'Chemical'
Group By C.compname
Having Count(P.pat_id) >= 3;

Prompt 9
Select T.CN
From (Select C.compname as CN, CT.subcatname As subct, Count(P.pat_id) AS CNT
	  FROM (Company C INNER JOIN Patent P ON P.assignee = C.assignee), Categories CT
	  Where P.cat = CT.cat AND P.subcat = CT.subcat AND CT.catnamelong = 'Chemical'
	  Group By C.compname, CT.subcatname) T
Where T.CNT IN ( Select Max(Count(P1.pat_id))
   	  			 FROM (Company C1 INNER JOIN Patent P1 ON P1.assignee = C1.assignee), Categories CT1
	  			 Where P1.cat = CT1.cat AND P1.subcat = CT1.subcat AND CT1.catnamelong = 'Chemical'
	  			 Group By C1.compname, CT1.subcatname
	           );

Prompt 10
Select T.FN, T.LN, T.CNT
FROM (Select I0.firstname AS FN , I0.lastname AS LN , Count(P0.pat_id) AS CNT
	  From (Patent P0 INNER JOIN Inventor I0 ON P0.pat_id = I0.patentnum), Categories C0
	  Where P0.cat = C0.cat AND P0.subcat = C0.subcat AND C0.catnamelong = 'Electrical AND Electronic'
	  Group By I0.firstname, I0.lastname) T
Where T.CNT IN (Select Max(Count(P.pat_id))
				From (Patent P INNER JOIN Inventor I ON P.pat_id = I.patentnum), Categories C
				Where P.cat = C.cat AND P.subcat = C.subcat AND C.catnamelong = 'Electrical AND Electronic'
				Group By I.firstname, I.lastname);




prompt 11
Select T.FN, T.LN
From  (Select C.cat as CATEGORY, I.firstname as FN, I.lastname as LN, Count(I.patentnum) as CNT 
 	  From (INVENTOR I INNER JOIN PATENT P ON I.patentnum = P.pat_id), Categories C 
	  Where C.cat = P.cat AND C.subcat = P.subcat
      Group By C.cat, I.firstname, I.lastname, I.patentnum)T
Where T.CNT IN  (Select Max(count(I1.patentnum))
					    From (INVENTOR I1 INNER JOIN PATENT P1 ON I1.patentnum = P1.pat_id)
					    Where P1.cat = T.CATEGORY
					    Group By P1.cat, I1.firstname, I1.lastname, P1.pat_id);

prompt 12
Select T.companyname, T.CNT
From (Select C.compname as companyname , Count(P.pat_id) as CNT
	  From (Patent P INNER JOIN Company C ON P.assignee = C.assignee), Categories CT
	  Where P.cat = CT.cat AND P.subcat = CT.subcat AND CT.catnamelong = 'Electrical AND Electronic'
	  Group BY C.compname, CT.subcatname) T
Where T.CNT IN 	(Select Sum(Count(CT2.subcat))
				From Categories CT2
				Where CT2.catnamelong = 'Electrical AND Electronic'
				Group By CT2.cat, CT2.subcat);


Prompt 13
Select I.firstname, I.lastname
From (Inventor I INNER JOIN Patent P ON I.patentnum = P.pat_id), Categories C
Where P.cat = C.cat AND P.subcat = C.subcat AND C.catnamelong = 'Chemical'
Group By I.firstname, I.lastname, C.subcatname
Having Count(Distinct (C.subcat)) > 1;

Prompt 14

Select T.PAT_ID
From (Select P.pat_id as PAT_ID,Count(C.cited) as CNT
	  From (Patent P INNER JOIN Citations C ON P.pat_id = C.cited)
	  Group By P.pat_id) T
Where T.CNT IN (Select Max(Count(C2.cited))
	  			From (Patent P2 INNER JOIN Citations C2 ON P2.pat_id = C2.cited)
	  			Group By P2.pat_id);

Prompt 15
Select T.CATEGORY, T.CNT
From  (Select CT.cat AS CATEGORY, Count(C.cited) AS CNT
	  From (Patent P INNER JOIN Citations C ON P.pat_id = C.cited), Categories CT
	  Where CT.cat = P.cat AND CT.subcat = P.subcat
	  Group By CT.cat, C.cited) T
Where T.CNT IN (Select Max(Count(C2.cited))
			      From (Patent P2 INNER JOIN Citations C2 ON P2.pat_id = C2.cited), Categories CT2
			      Where CT2.cat = P2.cat AND CT2.subcat = P2.subcat AND CT2.cat = T.CATEGORY
			      Group By CT2.cat, C2.cited);

Prompt 16
Select T.PAT_ID
From (Select P.pat_id as PAT_ID,Count(C.cited) as CNT
	  From (Patent P INNER JOIN Citations C ON P.pat_id = C.citing)
	  Group By P.pat_id) T
Where T.CNT IN (Select Max(Count(C2.cited))
	  			From (Patent P2 INNER JOIN Citations C2 ON P2.pat_id = C2.citing)
	  			Group By P2.pat_id);

Prompt 17

Select I0.firstname, I0.lastname, I0.invseq, I0.city, I0.postate
From (Select I.firstname as FN, I.lastname as LN, Count(C.cited) as CNT
   	  From (Patent P INNER JOIN Citations C ON P.pat_id = C.cited), Inventor I
	  Where I.patentnum = P.pat_id
	  Group By I.firstname, I.lastname) T, Inventor I0
Where I0.firstname = T.FN AND I0.lastname = T.LN AND T.CNT In (Select Max(Count(C1.cited))
		   	    From (Patent P1 INNER JOIN Citations C1 ON P1.pat_id = C1.cited), Inventor I1
			    Where I1.patentnum = P1.pat_id
			    Group By I1.firstname, I1.lastname);

Prompt 18
Select I0.firstname, I0.lastname, I0.invseq, I0.city, I0.postate
From (Select I.firstname as FN, I.lastname AS LN, Count(I.patentnum) as CNT
	  From Inventor I INNER Join PATENT P On I.patentnum = P.pat_id
	  Where I.invseq = 1
	  Group By I.firstname, I.lastname) T, Inventor I0
Where I0.firstname = T.FN AND I0.lastname = T.LN AND T.CNT IN (Select Max(Count(I1.patentnum))
															   From Inventor I1 INNER Join PATENT P1 On I1.patentnum = P1.pat_id
															   Where I1.invseq = 1
															   Group By I1.firstname, I1.lastname);

Prompt 19
Select I0.firstname, I0.lastname, I0.invseq, I0.city, I0.postate
From (Select C.cat as CT , I.firstname as FN, I.lastname AS LN, Count(I.patentnum) as CNT
	  From (Inventor I INNER Join PATENT P On I.patentnum = P.pat_id), Categories C 
	  Where P.cat = C.cat AND P.subcat = C.subcat AND I.invseq = 1
	  Group By C.cat, I.firstname, I.lastname) T, Inventor I0
Where I0.firstname = T.FN AND I0.lastname = T.LN AND T.CNT IN (Select Max(Count(I1.patentnum))
															   From (Inventor I1 INNER Join PATENT P1 On I1.patentnum = P1.pat_id), Categories C1
															   Where P1.cat = C1.cat AND P1.subcat = C1.subcat AND C1.cat = T.CT AND I1.invseq = 1
															   Group By C1.cat, I1.firstname, I1.lastname);
Prompt 20
Select P.pat_id
From (Patent P INNER JOIN Categories CT ON CT.cat = P.cat AND CT.subcat = P.subcat), Citations C
Where CT.catnamelong = 'Chemical' AND (P.pat_id != C.cited)
Group By CT.cat, P.pat_id;

Prompt 21
	  Select Count(I.patentnum)
	  From (Patent P INNER JOIN Categories C ON P.cat = C.cat AND P.subcat = C.subcat), Inventor I
	  Where P.pat_id = I.patentnum AND I.postate = 'CA'
	  Group By C.cat, C.subcat;

Prompt 22
Select AVG(Count(I.patentnum))
From (Patent P INNER JOIN Company C on P.assignee = C.assignee), Inventor I
Where P.pat_id = I.patentnum AND  I.postate = 'NJ'
Group BY C.compname;

Prompt 23
Select C.compname
From (Patent P INNER JOIN Company C on P.assignee = C.assignee), Inventor I
Where P.pat_id = I.patentnum
Group By C.compname;

Prompt 24
Select AVG(Count(P.pat_id))
From (Patent P INNER Join Categories C ON C.cat = P.cat AND C.subcat = P.subcat), Inventor I
Where I.patentnum = P.pat_id AND C.catnamelong = 'Electrical AND Electronic'
Group BY I.patentnum;

Prompt 25
Select I.firstname, I.lastname, I.patentnum
From Inventor I , Citations C
Where I.patentnum = C.citing AND I.patentnum IN (Select I.patentnum
		   FROM Citations C2
		   Where I.patentnum != C.cited)
Group BY I.firstname, I.lastname, I.patentnum;