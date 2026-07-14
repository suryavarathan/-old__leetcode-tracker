// Last updated: 7/14/2026, 3:28:10 PM
/**************************\U0001f60e**************************/
function minimumBoxes(n) {
	if (n < 4) return n;
	let flat = 0, max = 0,places = 0, remaining;
	const calc = n => (n * (n + 1)) / 2;

	while (max < n) {
		flat++;
		places = calc(flat);
		max += places;
	}
	if (max === n) return places;

	max -= places;
	remaining = n - max;
	places = calc(flat - 1);
	flat = 0;
	while (calc(flat) < remaining) flat++;

	return places + flat;
};