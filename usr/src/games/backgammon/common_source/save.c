static char	sccsid[] = "	save.c	4.1	82/11/24	";

#include "back.h"

extern int	errno;

int	code[] = {
	0000413, 0000000, 0004000, 0000000, 0002000, 0000000, 0037060, 0000000,
	0001144, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0007400, 0036421, 0057320, 0140532, 0055004, 0150120, 0054520, 0054720,
	0152530, 0011611, 0010402, 0150772, 0064131, 0001431, 0002302, 0150131,
	0167531, 0003732, 0000000, 0167735, 0003724, 0000000, 0054335, 0065335,
	0001773, 0006757, 0000000, 0156400, 0175520, 0167401, 0000144, 0000000,
	0010404, 0000301, 0000000, 0000335, 0136335, 0157410, 0022357, 0000010,
	0157400, 0011757, 0000010, 0157400, 0173757, 0000007, 0175400, 0167405,
	0000004, 0000000, 0000004, 0000000, 0000000, 0126237, 0156410, 0002254,
	0001373, 0000757, 0000000, 0002000, 0000000, 0167735, 0003600, 0000000,
	0126335, 0156410, 0002254, 0001773, 0006757, 0000000, 0013400, 0016757,
	0000000, 0000000, 0167427, 0000026, 0000000, 0000000, 0035674, 0172037,
	0000004, 0000000, 0000000, 0000373, 0143757, 0000001, 0136000, 0000001,
	0050320, 0054757, 0000011, 0147000, 0050001, 0000004, 0007400, 0030302,
	0150136, 0004254, 0160533, 0125410, 0004020, 0001250, 0010253, 0010252,
	0010253, 0000741, 0010253, 0030403, 0000222, 0000716, 0002120, 0054724,
	0054720, 0010530, 0173033, 0002254, 0177655, 0000720, 0156530, 0157530,
	0177655, 0125630, 0077022, 0001773, 0006757, 0000005, 0150000, 0054520,
	0065724, 0001461, 0160001, 0125402, 0155420, 0125720, 0055010, 0001423,
	0144061, 0157400, 0150255, 0125630, 0077022, 0001373, 0154757, 0000001,
	0152400, 0014520, 0152405, 0172255, 0004024, 0107462, 0002000, 0174255,
	0002421, 0126720, 0126764, 0150770, 0107533, 0004214, 0000000, 0071022,
	0167630, 0003530, 0000000, 0175576, 0167401, 0000666, 0000000, 0050325,
	0002423, 0003742, 0010253, 0157000, 0135757, 0000010, 0125400, 0157010,
	0131757, 0000010, 0125400, 0150004, 0174255, 0006253, 0003741, 0010253,
	0150224, 0004253, 0173132, 0002254, 0002273, 0125726, 0140404, 0006253,
	0050132, 0125721, 0050004, 0004430, 0126321, 0005004, 0001423, 0046461,
	0141777, 0125532, 0050004, 0050320, 0156530, 0156520, 0114132, 0011253,
	0175576, 0167403, 0002142, 0000000, 0050320, 0150131, 0125532, 0030404,
	0177516, 0126735, 0175770, 0167401, 0000664, 0000000, 0050320, 0150132,
	0125532, 0011010, 0124006, 0125404, 0010420, 0124241, 0125410, 0150020,
	0174255, 0006253, 0054724, 0054720, 0010530, 0141440, 0125532, 0054404,
	0054720, 0012530, 0150026, 0125532, 0156404, 0156531, 0114132, 0011253,
	0175576, 0167403, 0002022, 0000000, 0050320, 0141531, 0125401, 0065414,
	0126366, 0105004, 0055320, 0002253, 0054321, 0011531, 0124007, 0125440,
	0030420, 0177306, 0126320, 0050004, 0000004, 0007000, 0126320, 0055404,
	0125462, 0050020, 0107712, 0177771, 0177777, 0150520, 0001120, 0040022,
	0125720, 0055010, 0035023, 0055303, 0002253, 0012531, 0150063, 0125532,
	0131404, 0102217, 0125400, 0011420, 0152004, 0010520, 0150004, 0006253,
	0150120, 0065520, 0054735, 0055335, 0125630, 0077022, 0001773, 0123757,
	0000003, 0150400, 0054520, 0004023, 0020250, 0010253, 0000716, 0002120,
	0050324, 0000004, 0004000, 0167736, 0002774, 0000000, 0010533, 0156414,
	0175533, 0167401, 0000016, 0000000, 0012300, 0150533, 0167533, 0003566,
	0000000, 0165431, 0000004, 0006000, 0126320, 0055404, 0000716, 0131532,
	0001617, 0125401, 0011420, 0160100, 0125406, 0035420, 0055735, 0000773,
	0062757, 0177777, 0150377, 0055120, 0125630, 0077022, 0000773, 0063757,
	0000000, 0152400, 0014120, 0147003, 0055001, 0001741, 0010253, 0156412,
	0004253, 0000773, 0001757, 0000002, 0131400, 0106217, 0125400, 0011420,
	0152006, 0004253, 0125724, 0125014, 0177617, 0125401, 0152020, 0150153,
	0050132, 0000004, 0167427, 0176666, 0177777, 0000000, 0016274, 0172037,
	0000004, 0000000, 0000000, 0004302, 0157536, 0175255, 0126335, 0175404,
	0167402, 0000064, 0000000, 0050325, 0001430, 0050324, 0150004, 0050001,
	0000004, 0000000, 0167427, 0176606, 0177777, 0000000, 0003274, 0172037,
	0050324, 0000004, 0000000, 0126335, 0156410, 0004617, 0003164, 0156600,
	0002254, 0001773, 0016757, 0000000, 0002000, 0000000, 0126335, 0156410,
	0004217, 0003164, 0156500, 0002254, 0001773, 0003757, 0000000, 0002000,
	0167427, 0176512, 0177777, 0000000, 0033274, 0172037, 0000004, 0000000,
	0007000, 0167725, 0043240, 0000000, 0027022, 0000711, 0016217, 0000112,
	0167400, 0043222, 0000000, 0000711, 0014217, 0000112, 0167400, 0043212,
	0000000, 0167736, 0043204, 0000000, 0103757, 0000106, 0157000, 0072757,
	0000106, 0167400, 0043170, 0000000, 0002335, 0003701, 0002254, 0175576,
	0167402, 0001046, 0000000, 0050320, 0150131, 0060757, 0000106, 0055400,
	0167724, 0043146, 0000000, 0065751, 0010405, 0150044, 0065552, 0065720,
	0164532, 0173552, 0001170, 0050131, 0055700, 0150520, 0050132, 0007431,
	0001170, 0050131, 0055700, 0150520, 0055520, 0001431, 0134461, 0150000,
	0055133, 0000713, 0055553, 0055721, 0012132, 0150713, 0167532, 0043042,
	0000000, 0004422, 0055721, 0014217, 0000112, 0011400, 0152003, 0002120,
	0000761, 0167401, 0043024, 0000000, 0177654, 0107701, 0000400, 0000000,
	0050131, 0107706, 0000400, 0000000, 0074120, 0050010, 0175757, 0000105,
	0156400, 0175400, 0167401, 0000572, 0000000, 0050320, 0074132, 0167402,
	0042750, 0000000, 0140120, 0050132, 0050321, 0014532, 0074300, 0167402,
	0042730, 0000000, 0175576, 0167401, 0000530, 0000000, 0050320, 0150532,
	0107532, 0177777, 0177777, 0122423, 0055320, 0132777, 0000105, 0140400,
	0167404, 0042656, 0000000, 0150520, 0050132, 0003423, 0000710, 0120777,
	0000105, 0074000, 0167402, 0042642, 0000000, 0140120, 0050132, 0002303,
	0065120, 0065320, 0105757, 0000105, 0144400, 0107401, 0045030, 0000000,
	0077777, 0000105, 0030400, 0177430, 0001170, 0050131, 0055701, 0167520,
	0042554, 0000000, 0055321, 0062757, 0000105, 0012400, 0150022, 0056777,
	0000105, 0167400, 0042540, 0000000, 0065720, 0050777, 0000105, 0144400,
	0167401, 0042512, 0000000, 0140553, 0055404, 0002120, 0006000, 0126320,
	0055404, 0055720, 0141132, 0055004, 0055320, 0030757, 0000105, 0145400,
	0065001, 0150120, 0065120, 0000004, 0007000, 0006302, 0150136, 0002254,
	0164533, 0176253, 0156411, 0175533, 0167401, 0177716, 0177777, 0055703,
	0176253, 0143520, 0050004, 0172255, 0126335, 0175410, 0167401, 0177116,
	0177777, 0050320, 0011532, 0150405, 0055532, 0002022, 0055320, 0002120,
	0055720, 0176255, 0055320, 0174255, 0002335, 0001701, 0004254, 0175576,
	0167402, 0000226, 0000000, 0050320, 0150531, 0126531, 0017364, 0150031,
	0126531, 0010764, 0150023, 0176255, 0150120, 0174255, 0150121, 0060540,
	0002300, 0176255, 0002300, 0174255, 0126720, 0050364, 0126727, 0152764,
	0011120, 0150742, 0055532, 0132030, 0001170, 0050131, 0055300, 0150520,
	0055520, 0124031, 0001170, 0050131, 0055300, 0141120, 0050133, 0002306,
	0150120, 0110757, 0000104, 0040000, 0010552, 0000221, 0167427, 0175416,
	0177777, 0000000, 0010674, 0172037, 0126320, 0167404, 0002134, 0000000,
	0050324, 0000004, 0000000, 0167701, 0002120, 0000000, 0002254, 0156576,
	0150001, 0051534, 0057320, 0136134, 0017421, 0150321, 0035757, 0000004,
	0050000, 0121700, 0167404, 0002062, 0000000, 0000004, 0000000, 0126320,
	0050004, 0126320, 0051010, 0002423, 0051321, 0012401, 0152010, 0075521,
	0050122, 0051120, 0011404, 0150413, 0051120, 0001436, 0050324, 0150004,
	0050001, 0000004, 0167427, 0175246, 0177777, 0000000, 0002274, 0172037,
	0000004, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0004014, 0000000, 0000005, 0000000, 0024100, 0024443,
	0066543, 0072147, 0061456, 0072162, 0027060, 0004543, 0027064, 0020063,
	0061450, 0072162, 0027060, 0024543, 0024040, 0062502, 0065562, 0066145,
	0074545, 0020051, 0027464, 0034461, 0034057, 0000062, 0062411, 0062570,
	0066143, 0061456, 0030411, 0030456, 0034011, 0027462, 0032460, 0030457,
	0004461, 0000000, 0072457, 0071163, 0063457, 0066541, 0071545, 0061057,
	0061541, 0063553, 0066541, 0067555, 0000156, 0060542, 0065543, 0060547,
	0066555, 0067157, 0071400, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000001, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000002, 0000001,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000006, 0000002, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0005010, 0000000, 0045060, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000, 0000000,
	0000004, 0000000, 0000004, 0002664, 0000000, 0000000, 0000013, 0000000,
	0000004, 0000222, 0000104, 0000000, 0000023, 0000000, 0000006, 0000000,
	0004074, 0000000, 0000033, 0000000, 0000004, 0000000, 0000150, 0000000,
	0000043, 0000000, 0000004, 0003604, 0000170, 0000000, 0000053, 0000000,
	0000004, 0003317, 0000224, 0000000, 0000064, 0000000, 0000004, 0003317,
	0000244, 0000000, 0000073, 0000000, 0000004, 0001626, 0000260, 0000000,
	0000104, 0000000, 0000004, 0003627, 0000274, 0000000, 0000115, 0000000,
	0000004, 0001571, 0001364, 0000000, 0000124, 0000000, 0000004, 0002664,
	0001364, 0000000, 0000134, 0000000, 0000004, 0003642, 0001404, 0000000,
	0000145, 0000000, 0000004, 0001673, 0001444, 0000000, 0000155, 0000000,
	0000004, 0003473, 0001464, 0000000, 0000164, 0000000, 0000004, 0001673,
	0001540, 0000000, 0000174, 0000000, 0000004, 0003614, 0001560, 0000000,
	0000205, 0000000, 0000004, 0003067, 0002634, 0000000, 0000214, 0000000,
	0000004, 0001701, 0002734, 0000000, 0000223, 0000000, 0000004, 0003200,
	0003004, 0000000, 0000233, 0000000, 0000007, 0002562, 0004000, 0000000,
	0000244, 0000000, 0000005, 0002416, 0000000, 0000000, 0000252, 0000000,
	0000005, 0001576, 0000104, 0000000, 0000260, 0000000, 0000005, 0001640,
	0000244, 0000000, 0000266, 0000000, 0000007, 0000222, 0004010, 0000000,
	0000275, 0000000, 0000005, 0003572, 0000150, 0000000, 0000304, 0000000,
	0000005, 0004034, 0000260, 0000000, 0000313, 0000000, 0000005, 0003604,
	0000170, 0000000, 0000322, 0000000, 0000005, 0003317, 0000232, 0000000,
	0000332, 0000000, 0000005, 0001626, 0001164, 0000000, 0000344, 0000000,
	0000011, 0003627, 0005020, 0000000, 0000353, 0000000, 0000005, 0001146,
	0000274, 0000000, 0000364, 0000000, 0000005, 0004225, 0003012, 0000000,
	0000373, 0000000, 0000005, 0003642, 0001372, 0000000, 0000402, 0000000,
	0000007, 0001456, 0004170, 0000000, 0000410, 0000000, 0000005, 0003463,
	0001404, 0000000, 0000420, 0000000, 0000011, 0003012, 0005030, 0000000,
	0000430, 0000000, 0000005, 0003253, 0001560, 0000000, 0000440, 0000000,
	0000005, 0003114, 0001032, 0000000, 0000450, 0000000, 0000005, 0003001,
	0001226, 0000000, 0000460, 0000000, 0000007, 0002664, 0005010, 0000000,
	0000472, 0000000, 0000005, 0003473, 0001452, 0000000, 0000501, 0000000,
	0000005, 0001571, 0002334, 0000000, 0000507, 0000000, 0000011, 0002732,
	0025030, 0000000, 0000517, 0000000, 0000005, 0001673, 0001512, 0000000,
	0000525, 0000000, 0000005, 0002033, 0001464, 0000000, 0000533, 0000000,
	0000005, 0003614, 0001546, 0000000, 0000542, 0000000, 0000005, 0003200,
	0002734, 0000000, 0000547, 0000000, 0000005, 0001701, 0002664, 0000000,
	0000555, 0000000, 0000005, 0003067, 0002370, 0000000, 0000566, 0000000,
	0000011, 0002714, 0045060, 0000000, 0000573, 0000000, 0000005, 0002717,
	0002642, 0000000, 0000600, 0000000, 0071143, 0030164, 0067456, 0062400,
	0062570, 0066143, 0067456, 0057400, 0061563, 0071543, 0062151, 0062400,
	0062570, 0066143, 0067456, 0062400, 0062570, 0073143, 0067456, 0062400,
	0062570, 0073143, 0027145, 0000157, 0074145, 0072151, 0067456, 0061400,
	0071145, 0067562, 0027162, 0000157, 0066146, 0061163, 0063165, 0067456,
	0062000, 0072141, 0027141, 0000157, 0071546, 0060564, 0027164, 0000157,
	0071551, 0072141, 0074564, 0067456, 0061400, 0067554, 0062563, 0067456,
	0071400, 0072164, 0027171, 0000157, 0067551, 0072143, 0027154, 0000157,
	0060555, 0066154, 0061557, 0067456, 0047400, 0071142, 0027153, 0000157,
	0062165, 0073151, 0067456, 0073400, 0064562, 0062564, 0067456, 0057400,
	0067145, 0064566, 0067562, 0000156, 0072163, 0071141, 0000164, 0066537,
	0064541, 0000156, 0062537, 0064570, 0000164, 0061555, 0072557, 0072156,
	0057400, 0074145, 0061545, 0000154, 0062543, 0071162, 0071157, 0057400,
	0074145, 0061545, 0000166, 0062537, 0062570, 0073143, 0000145, 0057537,
	0066143, 0060545, 0072556, 0000160, 0062537, 0071162, 0067556, 0057400,
	0063137, 0071554, 0072542, 0000146, 0073537, 0064562, 0062564, 0057400,
	0071546, 0060564, 0000164, 0057537, 0067551, 0000142, 0064537, 0060563,
	0072164, 0000171, 0057537, 0067563, 0072542, 0000146, 0066537, 0066141,
	0067554, 0000143, 0063137, 0066146, 0071565, 0000150, 0063137, 0066143,
	0071557, 0000145, 0057537, 0060554, 0072163, 0072542, 0000146, 0061537,
	0067554, 0062563, 0057400, 0071146, 0062545, 0057400, 0071537, 0061151,
	0063165, 0057400, 0072147, 0074564, 0057400, 0072163, 0074564, 0057400,
	0067551, 0072143, 0000154, 0062165, 0073151, 0057400, 0061163, 0065562,
	0057400, 0062562, 0066141, 0067554, 0000143, 0062537, 0062156, 0057400,
	0071142, 0000153, 0,
};

static char	confirm[] = "Are you sure you want to leave now?";
static char	prompt[] = "Enter a file name:  ";
static char	exist1[] = "The file '";
static char	exist2[] =
	"' already exists.\nAre you sure you want to use this file?";
static char	cantuse[] = "\nCan't use ";
static char	saved[] = "This file has been saved on the file '";
static char	type[] = "'.\nType '";
static char	rec[] = "' to recover your game.\n\n";
static char	cantrec[] = "Can't recover file:  ";

save (n)
register int	n;

{
	register int	fdesc;
	register char	*fs;
	char		fname[50];

	if (n)  {
		if (tflag)  {
			curmove (20,0);
			clend();
		} else
			writec ('\n');
		writel (confirm);
		if (! yorn(0))
			return;
	}
	cflag = 1;
	for (;;)  {
		writel (prompt);
		fs = fname;
		while ((*fs = readc()) != '\n')  {
			if (*fs == tty.sg_erase)  {
				if (fs > fname)  {
					fs--;
					if (tflag)
						curmove (curr,curc-1);
					else
						writec (*fs);
				} else
					writec ('\007');
				continue;
			}
			writec (*fs++);
		}
		*fs = '\0';
		if ((fdesc = open(fname,2)) == -1 && errno == 2)  {
			if ((fdesc = creat (fname,0700)) != -1)
			break;
		}
		if (fdesc != -1)  {
			if (tflag)  {
				curmove (18,0);
				clend();
			} else
				writec ('\n');
			writel (exist1);
			writel (fname);
			writel (exist2);
			cflag = 0;
			close (fdesc);
			if (yorn (0))  {
				unlink (fname);
				fdesc = creat (fname,0700);
				break;
			} else  {
				cflag = 1;
				continue;
			}
		}
		writel (cantuse);
		writel (fname);
		writel (".\n");
		close (fdesc);
		cflag = 1;
	}
	write (fdesc,code,sizeof code);
	write (fdesc,board,52);
	write (fdesc,off,4);
	write (fdesc,in,4);
	write (fdesc,dice,4);
	write (fdesc,&cturn,2);
	write (fdesc,&dlast,2);
	write (fdesc,&pnum,2);
	write (fdesc,&rscore,2);
	write (fdesc,&wscore,2);
	write (fdesc,&gvalue,2);
	write (fdesc,&raflag,2);
	close (fdesc);
	if (tflag)
		curmove (18,0);
	writel (saved);
	writel (fname);
	writel (type);
	writel (fname);
	writel (rec);
	if (tflag)
		clend();
	getout ();
}

recover (s)
char	*s;

{
	register int	i;
	int		fdesc;

	if ((fdesc = open (s,0)) == -1)
		norec (s);
	read (fdesc,board,52);
	for (i = 0; i < 26; i++)
		if (board[i] != code[i])
			norec (s);
	if (lseek (fdesc,(long) sizeof code,0) == -1)
		norec (s);
	read (fdesc,board,52);
	read (fdesc,off,4);
	read (fdesc,in,4);
	read (fdesc,dice,4);
	read (fdesc,&cturn,2);
	read (fdesc,&dlast,2);
	read (fdesc,&pnum,2);
	read (fdesc,&rscore,2);
	read (fdesc,&wscore,2);
	read (fdesc,&gvalue,2);
	read (fdesc,&raflag,2);
	close (fdesc);
	rflag = 1;
}

norec (s)
register char	*s;

{
	register char	*c;

	tflag = 0;
	writel (cantrec);
	c = s;
	while (*c != '\0')
		writec (*c++);
	getout ();
}
