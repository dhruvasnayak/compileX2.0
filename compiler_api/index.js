const express = require('express');
const bodyParser = require("body-parser");
const compiler = require("compilex")

const app = express();
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));

const options = { stats: true };
compiler.init(options);

app.post('/api/compilex', async (req, res) => {
    try {
        const { code, input, language } = req.body;
        if (language === "python") {
            if (!input) {
                var envData = { OS: "windows" };
                compiler.compilePython(envData, code, function (data) {
                    if (data.error) {
                        data.output = data.error;
                        res.send(data);
                    } else {
                        res.send(data);
                    }
                });
            } else {
                var envData = { OS: "windows" };
                compiler.compilePythonWithInput(envData, code, input, function (data) {
                    if (data.error) {
                        data.output = data.error;
                        res.send(data);
                    } else {
                        res.send(data);
                    }
                })
            }
        }
         else {
            if (!input) {
                var envData = { OS: "windows", cmd: "g++", options: { timeout: 5000 } };
                compiler.compileCPP(envData, code, function (data) {
                    if (data.error) {
                        data.output = data.error;
                        res.send(data);

                    } else {
                        res.send(data);
                    }
                });
            } else {
                var envData = { OS: "windows", cmd: "g++", options: { timeout: 5000 } };
                compiler.compileCPPWithInput(envData, code, input, function (data) {
                    if (data.error) {
                        data.output = data.error;
                        res.send(data);
                    } else {
                        res.send(data);
                    }
                });
            }
        }
    } catch (error) {
        res.status(500).send("Internal Server Error");
    }
});

app.listen(5000, () => console.log("running on port 5000"));
