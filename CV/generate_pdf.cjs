const puppeteer = require('puppeteer');
const path = require('path');

(async () => {
    try {
        const browser = await puppeteer.launch({
            args: ['--no-sandbox', '--disable-setuid-sandbox']
        });
        const page = await browser.newPage();
        const htmlPath = 'file://' + path.resolve(__dirname, 'cv.html');

        await page.goto(htmlPath, { waitUntil: 'networkidle0' });

        await page.pdf({
            path: 'bruno_goncalves_cv.pdf',
            format: 'A4',
            printBackground: true,
            margin: {
                top: '0cm',
                bottom: '0cm',
                left: '0cm',
                right: '0cm'
            }
        });

        console.log('PDF generated successfully.');
        await browser.close();
    } catch (e) {
        console.error('Error generating PDF:', e);
        process.exit(1);
    }
})();
