let resultArray = ['| 序号 | 难度 | 题目 | 标签 | 思路 |','| ---- | ---- | ---- | ---- | ---- |'];
let table = document.querySelector('.reactable-data');
for (let row of table.children) {
    if (row.querySelector('.text-success')) {
        let cols = row.querySelectorAll('td');
        let order = cols[1].innerHTML;
        let title = row.querySelector('.question-title a');
        let titleName = title.innerHTML;
        let titleLink = title.getAttribute('href');
        let level = cols[5].querySelector('span').innerHTML;
        resultArray.push(`| ${order} | ${level} | [${titleName}](https://leetcode-cn.com${titleLink}) |  |  |`);
    }
}
let resultString = resultArray.join('\n');
console.log('复制内容：');
console.log(resultString);
alert('请手动复制监控台输出的内容');