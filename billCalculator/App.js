import { useState } from "react";

export default function App() {
  return (
    <div className="App">
      <TipCalculator />
    </div>
  );
}

function TipCalculator() {
  const [bill, setBill] = useState("");
  const [per1, setPer1] = useState(0);
  const [per2, setPer2] = useState(0);

  return (
    <div>
      <Bill bill={bill} handleBill={setBill} />
      <Percentage bill={bill} per={per1} handlePer={setPer1}>
        How did you like the service?
      </Percentage>
      <Percentage bill={bill} per={per2} handlePer={setPer2}>
        How did your friend like the service?
      </Percentage>
      {bill > 0 && (
        <>
          <Output bill={bill} per1={per1} per2={per2} />

          <Reset
            handleBill={setBill}
            handlePer1={setPer1}
            handlePer2={setPer2}
          />
        </>
      )}
    </div>
  );
}

function Bill({ bill, handleBill }) {
  return (
    <div>
      <label>How much was the bill?</label>
      <input
        type="text"
        placeholder="bill"
        value={bill}
        onChange={(e) => handleBill(Number(e.target.value))}
      ></input>
    </div>
  );
}
function Percentage({ children, bill, per, handlePer }) {
  return (
    <div>
      <label>{children}</label>
      <select value={per} onChange={(e) => handlePer(Number(e.target.value))}>
        <option value="0">Dissatisfied(0%)</option>
        <option value="5">It was okay(5%)</option>
        <option value="10">It was good(10%)</option>
        <option value="20">Absolutely amazing(20%)</option>
      </select>
    </div>
  );
}
function Output({ bill, per1, per2 }) {
  return (
    <div>
      <h3>
        You pay ${bill + (bill * (per1 + per2)) / 200} (${bill}+$
        {(bill * (per1 + per2)) / 200} tip)
      </h3>
    </div>
  );
}
function Reset({ handleBill, handlePer1, handlePer2 }) {
  function handleClick() {
    handleBill(0);
    handlePer1(0);
    handlePer2(0);
  }
  return (
    <div>
      <button onClick={handleClick}>Reset</button>
    </div>
  );
}
