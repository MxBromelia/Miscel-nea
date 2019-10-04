map('Australia',
	[wa : [nt,sa], nt: [wa,sa,qld], qld: [nt,sa,nsw],
	 nsw: [qld,sa,vic], vic: [sa,nsw], tas: [],
	 sa : [wa,nt,qld,nsw,vic]]).

map('West Europe',
	[portugal : [spain],
	 spain    : [portugal,france],
	 belgium  : [france,holland,luxemburg,germany],
	 holland  : [belgium,germany],
	 luxemburg: [france,belgium,germany],
	 switzerld: [france,germany,austria,italy],
	 italy    : [france,switzerld,austria],
	 austria  : [germany,switzerld,italy],
	 france   : [spain,belgium,luxemburg,germany,switzerld,italy],
	 germany  : [holland,belgium,luxemburg,france,switzerld,austria]]).

paint(MapName,Colours,ColouredMap) :-
	map(MapName,StateList),
	arrange_colours(StateList,Colours,[],ColouredMap).

arrange_colours([S:Nbs|Rest],Colours,ChosenColours,Result) :-
	member(C,Colours),
	different(C,Nbs,ChosenColours),
	arrange_colours(Rest,Colours,[S:C|ChosenColours],Result).
arrange_colours([],_,Result,Result).

different(C,Nbs,[S1:C1|Rest]) :-
	not((member(S1,Nbs),C=C1)),
	different(C,Nbs,Rest).
different(_,_,[]).