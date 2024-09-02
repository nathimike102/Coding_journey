document.addEventListener('DOMContentLoaded', () => {
  const API_URL = 'https://clist.by/api/v1/contest/?upcoming=true&resource__name__in=codechef.com,leetcode.com,geeksforgeeks.org,codeforces.com&username=YOUR_USERNAME&api_key=YOUR_API_KEY';
  const contestList = document.getElementById('contest-list');

  fetch(API_URL)
    .then(response => response.json())
    .then(data => {
      const contests = data.objects;
      contests.forEach(contest => {
        const listItem = document.createElement('li');
        listItem.textContent = `${contest.event} - ${new Date(contest.start).toLocaleString()}`;
        contestList.appendChild(listItem);
      });
    })
    .catch(error => console.error('Error fetching contests:', error));
});