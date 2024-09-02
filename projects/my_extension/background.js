const API_URL = 'https://clist.by/api/v1/contest/?upcoming=true&resource__name__in=codechef.com,leetcode.com,geeksforgeeks.org,codeforces.com&username=YOUR_USERNAME&api_key=YOUR_API_KEY';

function fetchContests() {
  fetch(API_URL)
    .then(response => response.json())
    .then(data => {
      const contests = data.objects;
      contests.forEach(contest => {
        const startTime = new Date(contest.start);
        const now = new Date();
        const timeDiff = startTime - now;

        if (timeDiff > 0 && timeDiff < 24 * 60 * 60 * 1000) { // Notify if contest is within 24 hours
          browser.notifications.create({
            type: 'basic',
            iconUrl: 'icons/icon48.png',
            title: 'Upcoming Coding Contest',
            message: `${contest.event} starts at ${startTime.toLocaleString()}`
          });
        }
      });
    })
    .catch(error => console.error('Error fetching contests:', error));
}

// Fetch contests every hour
setInterval(fetchContests, 60 * 60 * 1000);
fetchContests();