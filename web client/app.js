const btnConnect = document.getElementById("connect");
const sendDiv = document.getElementById("interface");
const inputText = document.getElementById("inputText");
const sendBtn = document.getElementById("send");
let port = 0;

sendDiv.style.visibility = "hidden";

async function portConnecting() {
    try {
        port = await navigator.serial.requestPort();
        sendDiv.style.visibility = "visible"
    } catch (err) {
        console.error(`error: ${err.message}`);
    }
}

async function write(message){
    try {
        await port.open({ baudRate: 9600 });
        const writer = port.writable.getWriter();
        await writer.write(new TextEncoder().encode(message));
        writer.releaseLock();
        await port.close();
    } catch (err) {
        console.error(`Erro ao escrever: ${err.message}`);
    }
}

async function sendMsg(){
    if (port) {
        let input = inputText.value;
        write(input);
    } else {
        console.error('Port not connected');
    }
}

btnConnect.addEventListener("click", portConnecting);
sendBtn.addEventListener("click", sendMsg)

