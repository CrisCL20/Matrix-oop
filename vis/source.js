
let df = 'diffeq.csv';

d3.csv(df).then(function(loadedData){

    let data = [];
    let labels = [];

    for(let i = 0;i<loadedData.length;i++){

        let t = loadedData[i].t;
        let y = loadedData[i].y;
        
        labels.push(t);
        data.push(y);

    }

    let options = {
        type: 'line',
        data: {
            labels : labels,
            datasets : [{
                data : data,
                fill : false,
                pointRadius : 0,
                pointHoverRadius : 0,
                borderColor : 'rgb(234,82,49)'
            }]
        }
    };

    let chart = new Chart(document.getElementById('canvas'),options);

});

